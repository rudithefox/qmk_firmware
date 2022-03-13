#include QMK_KEYBOARD_H

#include <sendstring_norman.h>


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _NORMAN,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_NORMAN] = LAYOUT( \
     NM_Q,    NM_W,    NM_D,    NM_F,    NM_K,                       NM_J,    NM_U,    NM_R,    NM_L,    NM_SCLN,    \
       NM_A,    NM_S,    NM_E,    NM_T,    NM_G,                       NM_Y,    NM_N,    NM_I,    NM_O,    NM_H, \
         NM_Z,    NM_X,    NM_C,    NM_V,    NM_B,                       NM_P,    NM_M,    NM_COMM, NM_DOT,  NM_SLSH, \
		LGUI_T(KC_ENT), LT(_LOWER, KC_ESC), SFT_T(KC_BSPC),    KC_SPC, LT(_RAISE, KC_TAB), CTL_T(KC_ENT)    \
),

[_RAISE] = LAYOUT( \
  KC_EXLM,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,      KC_PLUS, KC_7,     KC_8,   KC_9, KC_0,    \
  KC_CIRC,    KC_AMPR,  KC_TILD, KC_PIPE, KC_BSLS,      KC_MINUS,  KC_4,     KC_5,   KC_6, KC_EQL, \
KC_DQT,     KC_QUOT,  KC_UNDS, KC_GRV,  _______,      KC_ASTR,  KC_1,     KC_2,   KC_3, KC_DOT, \
                        _______, MO(_ADJUST), _______,      _______,  _______, _______                    \
),


[_LOWER] = LAYOUT( \
  KC_ESC,   KC_HOME, KC_UP,   KC_END,   KC_PGUP,     _______, KC_LPRN, KC_RPRN,  _______, _______,
  KC_VOLU,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    _______, KC_LBRC, KC_RBRC,  _______, _______, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  _______,      _______, KC_LCBR, KC_RCBR,  _______,  _______, \
                  _______, _______, _______,      _______,  MO(_ADJUST),  _______                    \
),

[_ADJUST] =  LAYOUT( \
  _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,   KC_MS_WH_UP,        		RESET,   KC_F1,    KC_F2,   KC_F3,    KC_F4, \
  _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  KC_MS_WH_DOWN,      		KC_TAB,  KC_F5, KC_F6, KC_F7,   KC_F8, \
  _______, _______,    _______,    _______,     _______,      				KC_LALT, KC_F9,  KC_F10, KC_F11,  KC_F12, \
                  	_______, _______, _______,                		_______, _______,  _______                    \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
