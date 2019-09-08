#include QMK_KEYBOARD_H

 //Define Layers
 enum preonic_layers {
  _QWERTY, 
  _NUMPAD,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _GREEK,
 };

 //Define Keycodes
 enum preonic_keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};
 
 //Define Unicode
 enum unicode_names {
    ALPHA,
    BETA,
    GAMMA,
    DELTA,
    EPSILON,
    ZETA,
    ETA,
    THETA,
    IOTA,
    KAPPA,
    LAMBDA,
    MU,
    NU,
    XI,
    OMICRON,
    PI,
    RHO,
    SIGMA,
    TAU,
    UPSILON,
    PHI,
    CHI,
    PSI,
    OMEGA,
    LALPHA,
    LBETA,
    LGAMMA,
    LDELTA,
    LEPSILON,
    LZETA,
    LETA,
    LTHETA,
    LIOTA,
    LKAPPA,
    LLAMBDA,
    LMU,
    LNU,
    LXI,
    LOMICRON,
    LPI,
    LRHO,
    LSIGMA,
    LTAU,
    LUPSILON,
    LPHI,
    LCHI,
    LPSI,
    LOMEGA,
};

 #include "dynamic_macro.h"
 //Define Shorter Keycodes for Macros
 #define QWERTY TO(_QWERTY)
 #define NUMPAD TO(_NUMPAD)
 #define DVORAK TO(_DVORAK)
 #define LOWER TO(_LOWER)
 #define RAISE TO(_RAISE)
 #define GR_ESC LT(_GREEK, KC_ESC)
 #define FN_MENU LT(_FUNCTION, KC_APP)
 #define LO_BACK LT(_LOWER, KC_BSPC)
 #define RS_SPACE LT(_RAISE, KC_SPC)
 #define KC_DMR1 DYN_REC_START1
 #define KC_DMR2 DYN_REC_START2
 #define KC_DMP1 DYN_MACRO_PLAY1
 #define KC_DMP2 DYN_MACRO_PLAY2
 #define KC_DMRS DYN_REC_STOP

 const uint32_t PROGMEM unicode_map[] = {
    [ALPHA] = 0x0391, // Α
    [BETA] = 0x0392, // Β
    [GAMMA] = 0x0393, // Γ
    [DELTA] = 0x0394, // Δ
    [EPSILON] = 0x0395, // Ε
    [ZETA] = 0x0396, // Ζ
    [ETA] = 0x0397, // Η
    [THETA]  = 0x0398, // Θ
    [IOTA] = 0x0399, // Ι
    [KAPPA] = 0x039A, // Κ
    [LAMBDA] = 0x039B, // Λ
    [MU] = 0x039C, // Μ
    [NU] = 0x039D, // Ν
    [XI] = 0x039E, // Ξ
    [OMICRON]= 0x039F, // Ο
    [PI] = 0x03A0, // Π
    [RHO] = 0x03A1, // Ρ
    [SIGMA] = 0x03A3, // Σ
    [TAU] = 0x03A4, // Τ
    [UPSILON] = 0x03A5, // Υ
    [PHI] = 0x03A6, // Φ
    [CHI] = 0x03A7, // Χ
    [PSI] = 0x03A8, // Ψ
    [OMEGA] = 0x03A9, // Ω
    [LALPHA] = 0x03B1, // α
    [LBETA] = 0x03B2, // β
    [LGAMMA] = 0x03B3, // γ
    [LDELTA] = 0x03B4, // δ
    [LEPSILON] = 0x03B5, // ε
    [LZETA] = 0x03B6, // ζ
    [LETA] = 0x03B7, // η
    [LTHETA] = 0x03B8, // θ
    [LIOTA] = 0x03B9, // ι
    [LKAPPA] = 0x03BA, // κ
    [LLAMBDA] = 0x03BB, // λ
    [LMU] = 0x03BC, // μ
    [LNU] = 0x03BD, // ν 
    [LXI] = 0x03BE, // ξ
    [LOMICRON] = 0x03BF, // ο
    [LPI] = 0x03C0, // π
    [LRHO] = 0x03C1, // ρ
    [LSIGMA] = 0x03C3, // σ
    [LTAU] = 0x03C4, // τ
    [LUPSILON] = 0x03C5, // υ
    [LPHI] = 0x03C6, // φ
    [LCHI] = 0x03C7, // χ
    [LPSI] = 0x03C8, // ψ
    [LOMEGA] = 0x03C9, // ω
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Gr|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Menu | Back/lower  | Space/raise | Ctrl | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u ( \
  KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  GR_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SFTENT, \
  KC_LCPO, KC_LGUI, KC_LALT, FN_MENU, LO_BACK, RS_SPACE, KC_RCPC, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |  Del |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   P  |  Up  |   J  |      |   [  |   ]  |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  | Left | Down |Right |   A  |   (  |   )  |   4  |   5  |   6  |   +  |  ,   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Undo |  Cut | Copy |Paste |   {  |   }  |   1  |   2  |   3  |Enter | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Menu | Back/lower  | Space/raise |   0  |   .  | Menu | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_2x2u ( \
  KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_SLSH, KC_ASTR, KC_MINS,  KC_BSPC, \
  KC_TAB,  KC_P,    KC_UP,   KC_J,    KC_NO,   KC_LBRC, KC_RBRC, KC_7,    KC_8,    KC_9,    KC_PLUS,  KC_EQL, \
  KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_A,    KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,    KC_PLUS,  KC_COMM, \
  KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,KC_LCBR, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_ENT,   KC_RCTL, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_APP, LO_BACK, RS_SPACE, KC_0, KC_DOT, KC_APP,  KC_RALT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  | Back/Lower  | Space/Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_2x2u ( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, LO_BACK, RS_SPACE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |  Del |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   P  |  Up  |   J  |      |   [  |   ]  |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  | Left | Down |Right |      |   (  |   )  |   4  |   5  |   6  |   +  |  ,   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Undo |  Cut | Copy |Paste |   {  |   }  |   1  |   2  |   3  |Enter | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Menu | Back/lower  | Space/raise |   0  |   .  | Menu | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_preonic_2x2u ( \
  KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_SLSH, KC_ASTR, KC_MINS,  KC_BSPC, \
  KC_TAB,  KC_P,    KC_UP,   KC_J,    KC_NO,   KC_LBRC, KC_RBRC, KC_7,    KC_8,    KC_9,    KC_PLUS,  KC_EQL, \
  KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_A,    KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,    KC_PLUS,  KC_COMM, \
  KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,KC_LCBR, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_ENT,   KC_RCTL, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_APP, LO_BACK, RS_SPACE, KC_0, KC_DOT, KC_APP,  KC_RALT \
),

/* Greek
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   θ  |   ω  |   ε  |   ρ  |   τ  |   υ  |   ψ  |   ι  |   ο  |   π  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   α  |   σ  |   δ  |   φ  |   γ  |   η  |      |   κ  |   λ  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ζ  |   ξ  |   χ  |      |   β  |   ν  |   μ  |   ,  |   .  |  UP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Back/lower  | Space/raise |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GREEK] = LAYOUT_preonic_2x2u ( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC, \
 _______,  XP(LTHETA, THETA), XP(LOMEGA, OMEGA), XP(LEPSILON, EPSILON), XP(LRHO, RHO), XP(LTAU, TAU), XP(LUPSILON, UPSILON), XP(LPSI, PSI), XP(LIOTA, IOTA), XP(LOMICRON, OMICRON), XP(LPI, PI), KC_DEL, \
 _______,  XP(LALPHA, ALPHA), XP(LSIGMA, SIGMA), XP(LDELTA, DELTA), XP(LPHI, PHI),  XP(LGAMMA, GAMMA), XP(LETA, ETA), _______, XP(LKAPPA, KAPPA), XP(LLAMBDA, LAMBDA), _______, _______, \
 _______, XP(LZETA, ZETA), XP(LXI, XI),  XP(LCHI, CHI), _______, XP(LBETA, BETA), XP(LNU, NU), XP(LMU, MU),  _______, _______,  KC_UP, _______, \
 _______, _______, _______, _______, _______, _______, _______,                KC_LEFT,  KC_DOWN,  KC_RGHT \
),

/* Emoji
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ⚽  |  🍕  |  🌮  |  🍺 |  🎃 |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  💣 |  💥  |  ☢  |  💰  |  🐍  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  🦄 |  🧙  |  🦖  |  🌛 | 👎  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*[_EMOJI] = LAYOUT_preonic_2x2u ( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, X(SOCCER), X(PIZZA), X(TACO), X(BEER), X(PUMPKIN), KC_DEL, \
  _______, _______, _______, _______, _______, _______, X(BOMB), X(EXPLOSION), X(RADIOACTIVE), X(MONEY),  X(SNAKE), _______, \
  _______, _______, _______, _______, _______, _______, X(UNICORN), X(WIZARD), X(TREX), X(MOON), X(THUMB), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),*/

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F11 |  F12 |      |      |  (   |   )  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy |Paste |  {   |   }  |ISO ~ |ISO | |   /  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |    Lower    |    Raise    | Play | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_2x2u ( \
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F11,   KC_F12, _______, _______,   KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,  KC_LCBR, KC_RCBR, S(KC_NUHS),S(KC_NUBS),KC_SLSH,KC_VOLU, _______, \
  _______, _______, _______, _______, LOWER, RAISE, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F11 |  F12 |      |      |  (   |   )  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | DMRS | Undo |  Cut | Copy |Paste |  {   |   }  |ISO # |ISO / |   ?  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DM1R | DM2R | DM1P | DM2P |    Lower    |    Raise    | Next | Vol- | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u ( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F11,   KC_F12, _______, _______, KC_LPRN, KC_RPRN,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_DMRS, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,  KC_LCBR, KC_RCBR,  KC_NUHS, KC_NUBS, KC_QUES, KC_VOLU, _______, \
  KC_DMR1, KC_DMR2, KC_DMP1, KC_DMP2, LOWER, RAISE, KC_MNXT, KC_VOLD, KC_VOLD, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|DEBUG |EEPRST|      |      |      |Term1 |Term0 |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Numpad|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_2x2u ( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET, DEBUG, EEPROM_RESET, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL, \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY, NUMPAD, DVORAK,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

//Unicode Stuff
void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
};

//Music Stuff
#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2] = SONG(FANTASIE_IMPROMPTU);
float tone_numpad[][2]    = {
  {NOTE_E6, 10}   ,{NOTE_E6, 10}  ,{NOTE_REST, 10} ,{NOTE_E6, 10}   ,
  {NOTE_REST, 10} ,{NOTE_C6, 10}  ,{NOTE_E6, 10}   ,{NOTE_REST, 10} ,
  {NOTE_G6, 10}   ,{NOTE_REST, 30},
  {NOTE_G5, 10}   ,{NOTE_REST, 30}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void music_on_user(void) {
  music_scale_user();
}

void music_scale_user(void) {
  PLAY_SONG(music_scale);
}

#endif

//Layer stuff
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
    }    
  switch (keycode) 
        {
        case QWERTY:
          if (record->event.pressed) 
            {
              #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
              #endif
              set_single_persistent_default_layer(_QWERTY);
            }
          return false;
          break;
        case NUMPAD:
          if (record->event.pressed) 
            {
              #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_numpad);
              #endif
              set_single_persistent_default_layer(_NUMPAD);
            }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) 
            {
              set_single_persistent_default_layer(_DVORAK);
            }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) 
            {
              layer_on(_LOWER);
             update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
          else 
           {
              layer_off(_LOWER);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) 
            {
             layer_on(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
          else 
            {
              layer_off(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
          return false;
          break;
        }
    return true;
};
