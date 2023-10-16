--- src/input/sdl.c.orig	2023-10-08 02:12:37 UTC
+++ src/input/sdl.c
@@ -19,15 +19,23 @@
 
 #include "sdl.h"
 #include "../sdl.h"
+#include "../loop.h"
 
+#include <poll.h>
+#include <fcntl.h>
+#include <unistd.h>
 #include <Limelight.h>
 
 #define ACTION_MODIFIERS (MODIFIER_SHIFT|MODIFIER_ALT|MODIFIER_CTRL)
 #define QUIT_KEY SDLK_q
 #define QUIT_BUTTONS (PLAY_FLAG|BACK_FLAG|LB_FLAG|RB_FLAG)
 #define FULLSCREEN_KEY SDLK_f
-#define UNGRAB_KEY SDLK_z
+#define UNGRAB_MOUSE_KEY SDLK_m
+#define UNGRAB_WINDOW_KEY SDLK_z
 
+static bool isx11sdlcall = false;
+static int x11_sdl_event_handle(int fd);
+
 static const int SDL_TO_LI_BUTTON_MAP[] = {
   A_FLAG, B_FLAG, X_FLAG, Y_FLAG,
   BACK_FLAG, SPECIAL_FLAG, PLAY_FLAG,
@@ -51,6 +59,8 @@ typedef struct _GAMEPAD_STATE {
   int haptic_effect_id;
 #endif
   short id;
+  int fd;
+  bool fdadded;
   bool initialized;
 } GAMEPAD_STATE, *PGAMEPAD_STATE;
 
@@ -62,6 +72,22 @@ static GAMEPAD_STATE gamepads[MAX_GAMEPADS];
 static int keyboard_modifiers;
 static int activeGamepadMask = 0;
 
+static short keystatlist[0xFF];
+static void keyrelease(int keycode) {
+  keystatlist[keycode] = 0;
+}
+static void keypress(int keycode) {
+  keystatlist[keycode] = 1;
+}
+static void freeallkey () {
+  for (int i=0;i<0xFF;i++) {
+    if (keystatlist[i] == 1) {
+      keystatlist[i] = 0;
+      LiSendKeyboardEvent(0x80 << 8 | i, KEY_ACTION_UP, 0);
+    }
+  }
+}
+
 int sdl_gamepads = 0;
 
 static void send_controller_arrival(PGAMEPAD_STATE state) {
@@ -142,12 +168,22 @@ static PGAMEPAD_STATE get_gamepad(SDL_JoystickID sdl_i
 }
 
 static void add_gamepad(int joystick_index) {
+  int fd;
   SDL_GameController* controller = SDL_GameControllerOpen(joystick_index);
   if (!controller) {
     fprintf(stderr, "Could not open gamecontroller %i: %s\n", joystick_index, SDL_GetError());
     return;
   }
-
+  if (isx11sdlcall) {
+    char* controllerpath = SDL_GameControllerPath(controller);
+    fd = open(controllerpath, O_RDWR|O_NONBLOCK);
+    if (fd == -1) {
+       close(fd);
+       fprintf(stderr, "Could not open gamecontroller from path: %s\n", controllerpath);
+       return;
+    }
+  }
+  
   SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller);
   SDL_JoystickID joystick_id = SDL_JoystickInstanceID(joystick);
 
@@ -166,10 +202,15 @@ static void add_gamepad(int joystick_index) {
   // Create a new gamepad state
   state = get_gamepad(joystick_id, true);
   state->controller = controller;
+  if (isx11sdlcall) {
+    state->fd = fd;
+    loop_add_fd(state->fd, &x11_sdl_event_handle, POLLIN);
+    state->fdadded = true;
+  }
 
 #if !SDL_VERSION_ATLEAST(2, 0, 9)
   state->haptic = SDL_HapticOpenFromJoystick(joystick);
-  if (haptic && (SDL_HapticQuery(state->haptic) & SDL_HAPTIC_LEFTRIGHT) == 0) {
+  if (state->haptic && (SDL_HapticQuery(state->haptic) & SDL_HAPTIC_LEFTRIGHT) == 0) {
     SDL_HapticClose(state->haptic);
     state->haptic = NULL;
   }
@@ -182,6 +223,11 @@ static void add_gamepad(int joystick_index) {
   sdl_gamepads++;
 }
 
+static void x11_add_gamepad(int joystick_index) {
+  isx11sdlcall = true;
+  add_gamepad(joystick_index);
+}
+
 static void remove_gamepad(SDL_JoystickID sdl_id) {
   for (int i = 0;i<MAX_GAMEPADS;i++) {
     if (gamepads[i].initialized && gamepads[i].sdl_id == sdl_id) {
@@ -208,6 +254,20 @@ static void remove_gamepad(SDL_JoystickID sdl_id) {
   }
 }
 
+static void x11_remove_gamepad(SDL_JoystickID sdl_id) {
+  for (int i=0;i<MAX_GAMEPADS;i++) {
+    if (gamepads[i].initialized && gamepads[i].sdl_id == sdl_id) {
+      if (gamepads[i].fdadded) {
+        loop_remove_fd(gamepads[i].fd);
+        gamepads[i].fdadded = false;
+        close(gamepads[i].fd);
+      }
+      remove_gamepad(gamepads[i].sdl_id);
+      return;
+    }
+  }
+}
+
 void sdlinput_init(char* mappings) {
   memset(gamepads, 0, sizeof(gamepads));
 
@@ -317,15 +377,28 @@ int sdlinput_handle_event(SDL_Window* window, SDL_Even
         keyboard_modifiers &= ~modifier;
     }
 
-    LiSendKeyboardEvent(0x80 << 8 | button, event->type==SDL_KEYDOWN?KEY_ACTION_DOWN:KEY_ACTION_UP, keyboard_modifiers);
-
     // Quit the stream if all the required quit keys are down
-    if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == QUIT_KEY && event->type==SDL_KEYUP)
+    if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == QUIT_KEY && event->type==SDL_KEYUP) {
+      freeallkey();
       return SDL_QUIT_APPLICATION;
-    else if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == FULLSCREEN_KEY && event->type==SDL_KEYUP)
+    } else if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == FULLSCREEN_KEY && event->type==SDL_KEYUP) {
+      freeallkey();
       return SDL_TOGGLE_FULLSCREEN;
-    else if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == UNGRAB_KEY && event->type==SDL_KEYUP)
+    } else if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == UNGRAB_MOUSE_KEY && event->type==SDL_KEYUP) {
+      freeallkey();
       return SDL_GetRelativeMouseMode() ? SDL_MOUSE_UNGRAB : SDL_MOUSE_GRAB;
+    } else if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event->key.keysym.sym == UNGRAB_WINDOW_KEY && event->type==SDL_KEYUP) {
+      freeallkey();
+      return iskeyboardgrab ? SDL_WINDOW_UNGRAB : SDL_WINDOW_GRAB;
+    }
+    
+    if (event->type==SDL_KEYDOWN)
+        keypress(button);
+    else
+        keyrelease(button);
+
+    
+    LiSendKeyboardEvent(0x80 << 8 | button, event->type==SDL_KEYDOWN?KEY_ACTION_DOWN:KEY_ACTION_UP, keyboard_modifiers);
     break;
   case SDL_FINGERDOWN:
   case SDL_FINGERMOTION:
@@ -524,4 +597,139 @@ void sdlinput_set_controller_led(unsigned short contro
 #if SDL_VERSION_ATLEAST(2, 0, 14)
   SDL_GameControllerSetLED(state->controller, r, g, b);
 #endif
-}
\ No newline at end of file
+}
+
+static int x11_sdlinput_handle_event(SDL_Event* event) {
+  int button = 0;
+  unsigned char touchEventType;
+  PGAMEPAD_STATE gamepad;
+  switch (event->type) {
+  case SDL_CONTROLLERAXISMOTION:
+    gamepad = get_gamepad(event->caxis.which, false);
+    if (!gamepad)
+      return SDL_NOTHING;
+    switch (event->caxis.axis) {
+    case SDL_CONTROLLER_AXIS_LEFTX:
+      gamepad->leftStickX = event->caxis.value;
+      break;
+    case SDL_CONTROLLER_AXIS_LEFTY:
+      gamepad->leftStickY = -SDL_max(event->caxis.value, (short)-32767);
+      break;
+    case SDL_CONTROLLER_AXIS_RIGHTX:
+      gamepad->rightStickX = event->caxis.value;
+      break;
+    case SDL_CONTROLLER_AXIS_RIGHTY:
+      gamepad->rightStickY = -SDL_max(event->caxis.value, (short)-32767);
+      break;
+    case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
+      gamepad->leftTrigger = (unsigned char)(event->caxis.value * 255UL / 32767);
+      break;
+    case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
+      gamepad->rightTrigger = (unsigned char)(event->caxis.value * 255UL / 32767);
+      break;
+    default:
+      return SDL_NOTHING;
+    }
+    LiSendMultiControllerEvent(gamepad->id, activeGamepadMask, gamepad->buttons, gamepad->leftTrigger, gamepad->rightTrigger, gamepad->leftStickX, gamepad->leftStickY, gamepad->rightStickX, gamepad->rightStickY);
+    break;
+  case SDL_CONTROLLERBUTTONDOWN:
+  case SDL_CONTROLLERBUTTONUP:
+    gamepad = get_gamepad(event->cbutton.which, false);
+    if (!gamepad)
+      return SDL_NOTHING;
+    if (event->cbutton.button >= SDL_arraysize(SDL_TO_LI_BUTTON_MAP))
+      return SDL_NOTHING;
+
+    if (event->type == SDL_CONTROLLERBUTTONDOWN)
+      gamepad->buttons |= SDL_TO_LI_BUTTON_MAP[event->cbutton.button];
+    else
+      gamepad->buttons &= ~SDL_TO_LI_BUTTON_MAP[event->cbutton.button];
+
+    if ((gamepad->buttons & QUIT_BUTTONS) == QUIT_BUTTONS)
+      return SDL_QUIT_APPLICATION;
+
+    LiSendMultiControllerEvent(gamepad->id, activeGamepadMask, gamepad->buttons, gamepad->leftTrigger, gamepad->rightTrigger, gamepad->leftStickX, gamepad->leftStickY, gamepad->rightStickX, gamepad->rightStickY);
+    break;
+  case SDL_CONTROLLERDEVICEADDED:
+    x11_add_gamepad(event->cdevice.which);
+    break;
+  case SDL_CONTROLLERDEVICEREMOVED:
+    x11_remove_gamepad(event->cdevice.which);
+    break;
+#if SDL_VERSION_ATLEAST(2, 0, 14)
+  case SDL_CONTROLLERSENSORUPDATE:
+    gamepad = get_gamepad(event->csensor.which, false);
+    if (!gamepad)
+      return SDL_NOTHING;
+    switch (event->csensor.sensor) {
+    case SDL_SENSOR_ACCEL:
+      LiSendControllerMotionEvent(gamepad->id, LI_MOTION_TYPE_ACCEL, event->csensor.data[0], event->csensor.data[1], event->csensor.data[2]);
+      break;
+    case SDL_SENSOR_GYRO:
+      // Convert rad/s to deg/s
+      LiSendControllerMotionEvent(gamepad->id, LI_MOTION_TYPE_GYRO,
+                                  event->csensor.data[0] * 57.2957795f,
+                                  event->csensor.data[1] * 57.2957795f,
+                                  event->csensor.data[2] * 57.2957795f);
+      break;
+    }
+    break;
+  case SDL_CONTROLLERTOUCHPADDOWN:
+  case SDL_CONTROLLERTOUCHPADUP:
+  case SDL_CONTROLLERTOUCHPADMOTION:
+    gamepad = get_gamepad(event->ctouchpad.which, false);
+    if (!gamepad)
+      return SDL_NOTHING;
+    switch (event->type) {
+    case SDL_CONTROLLERTOUCHPADDOWN:
+      touchEventType = LI_TOUCH_EVENT_DOWN;
+      break;
+    case SDL_CONTROLLERTOUCHPADUP:
+      touchEventType = LI_TOUCH_EVENT_UP;
+      break;
+    case SDL_CONTROLLERTOUCHPADMOTION:
+      touchEventType = LI_TOUCH_EVENT_MOVE;
+      break;
+    default:
+      return SDL_NOTHING;
+    }
+    LiSendControllerTouchEvent(gamepad->id, touchEventType, event->ctouchpad.finger,
+                               event->ctouchpad.x, event->ctouchpad.y, event->ctouchpad.pressure);
+    break;
+#endif
+  }
+
+  return SDL_NOTHING;
+}
+
+static int x11_sdl_event_handle(int fd) {
+  SDL_Event event;
+  for (int i=0;i<MAX_GAMEPADS;i++) {
+    if (gamepads[i].fd == fd) {
+      int rc;
+      while (SDL_PollEvent(&event)) {
+        rc = x11_sdlinput_handle_event(&event);
+        if (rc == SDL_QUIT_APPLICATION)
+          return LOOP_RETURN;
+      }
+    }
+  }
+  return LOOP_OK;
+}
+
+void x11_sdl_init(char* mappings) {
+  isx11sdlcall = true;
+  sdlinput_init(mappings);
+}
+
+void x11_sdl_stop() {
+  for (int i=0;i<MAX_GAMEPADS;i++) {
+    if (gamepads[i].initialized && gamepads[i].fdadded) {
+      loop_remove_fd(gamepads[i].fd);
+      gamepads[i].fdadded = false;
+      close(gamepads[i].fd);
+      remove_gamepad(gamepads[i].sdl_id);
+    }
+  }
+  SDL_Quit();
+}
