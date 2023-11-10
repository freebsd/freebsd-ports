--- src/input/evdev.c.orig	2023-10-11 15:50:11 UTC
+++ src/input/evdev.c
@@ -38,10 +38,16 @@
 #include <limits.h>
 #include <unistd.h>
 #include <pthread.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <math.h>
 
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+extern bool isNoSdl;
+bool iskeyboardgrab = false;
+void grab_window(bool grabstat);
+static bool waitingToSwitchGrabOnModifierUp = false;
+static bool isgrabkeyrelease = false;
+
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 #define int16_to_le(val) val
 #else
 #define int16_to_le(val) ((((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00))
@@ -66,8 +72,8 @@ struct input_device {
   int hats_state[3][2];
   int fd;
   char modifiers;
-  __s32 mouseDeltaX, mouseDeltaY, mouseVScroll, mouseHScroll;
-  __s32 touchDownX, touchDownY, touchX, touchY;
+  int32_t mouseDeltaX, mouseDeltaY, mouseVScroll, mouseHScroll;
+  int32_t touchDownX, touchDownY, touchX, touchY;
   struct timeval touchDownTime;
   struct timeval btnDownTime;
   short controllerId;
@@ -127,6 +133,7 @@ int evdev_gamepads = 0;
 
 #define ACTION_MODIFIERS (MODIFIER_SHIFT|MODIFIER_ALT|MODIFIER_CTRL)
 #define QUIT_KEY KEY_Q
+#define GRAB_KEY KEY_Z
 #define QUIT_BUTTONS (PLAY_FLAG|BACK_FLAG|LB_FLAG|RB_FLAG)
 
 static bool (*handler) (struct input_event*, struct input_device*);
@@ -139,6 +146,22 @@ static int evdev_get_map(int* map, int length, int val
   return -1;
 }
 
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
+      LiSendKeyboardEvent(0x80 << 8 | keyCodes[i], KEY_ACTION_UP, 0);
+    }
+  }
+}
+
 static bool evdev_init_parms(struct input_device *dev, struct input_abs_parms *parms, int code) {
   int abs = evdev_get_map(dev->abs_map, ABS_MAX, code);
 
@@ -343,7 +366,7 @@ static bool evdev_handle_event(struct input_event *ev,
     if (dev->mouseHScroll != 0) {
       LiSendHScrollEvent(dev->mouseHScroll);
       dev->mouseHScroll = 0;
-    }
+    } 
     if (dev->gamepadModified) {
       if (dev->controllerId < 0) {
         for (int i = 0; i < MAX_GAMEPADS; i++) {
@@ -398,15 +421,41 @@ static bool evdev_handle_event(struct input_event *ev,
       }
 
       // After the quit key combo is pressed, quit once all keys are raised
-      if ((dev->modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS &&
-          ev->code == QUIT_KEY && ev->value != 0) {
-        waitingToExitOnModifiersUp = true;
-        return true;
-      } else if (waitingToExitOnModifiersUp && dev->modifiers == 0)
+      if ((dev->modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && ev->value != 0) {
+        if (ev->code == QUIT_KEY) {
+          waitingToExitOnModifiersUp = true;
+          return true;
+        } else if (ev->code == GRAB_KEY && iskeyboardgrab) {
+          waitingToSwitchGrabOnModifierUp = true;
+          return true;
+        }
+      }
+      if (waitingToSwitchGrabOnModifierUp) {
+        if (ev->code == GRAB_KEY && ev->value == 0) {
+          isgrabkeyrelease = true;
+          if (dev->modifiers != 0)
+            return true;
+        }
+        if (dev->modifiers == 0 && isgrabkeyrelease) {
+          waitingToSwitchGrabOnModifierUp = false;
+          isgrabkeyrelease = false;
+	  freeallkey();
+          grab_window(!iskeyboardgrab);
+          return true;
+        }
+      } else if (waitingToExitOnModifiersUp && dev->modifiers == 0) {
+	freeallkey();
+        grab_window(false);
         return false;
+      }
 
+      if (ev->value)
+        keypress(ev->code);
+      else
+        keyrelease(ev->code);
       short code = 0x80 << 8 | keyCodes[ev->code];
       LiSendKeyboardEvent(code, ev->value?KEY_ACTION_DOWN:KEY_ACTION_UP, dev->modifiers);
+
     } else {
       int mouseCode = 0;
       int gamepadCode = 0;
@@ -749,8 +798,10 @@ static int evdev_handle(int fd) {
       struct input_event ev;
       while ((rc = libevdev_next_event(devices[i].dev, LIBEVDEV_READ_FLAG_NORMAL, &ev)) >= 0) {
         if (rc == LIBEVDEV_READ_STATUS_SYNC)
-          fprintf(stderr, "Error: cannot keep up\n");
+          fprintf(stderr, "Error:%s(%d) cannot keep up\n", libevdev_get_name(devices[i].dev), i);
         else if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
+	  if (!iskeyboardgrab)
+	    break;
           if (!handler(&ev, &devices[i]))
             return LOOP_RETURN;
         }
@@ -840,7 +891,28 @@ void evdev_create(const char* device, struct mapping* 
      libevdev_has_event_code(evdev, EV_ABS, ABS_WHEEL) ||
      libevdev_has_event_code(evdev, EV_ABS, ABS_GAS) ||
      libevdev_has_event_code(evdev, EV_ABS, ABS_BRAKE));
+  bool is_acpibutton = 
+    is_keyboard && 
+    (strcmp(libevdev_get_name(evdev), "Sleep Button") == 0 ||
+    strcmp(libevdev_get_name(evdev), "Power Button") == 0);
+  bool is_likekeyboard = 
+    is_keyboard &&
+    (libevdev_get_id_version(evdev) > 1000 ||
+    libevdev_get_id_bustype(evdev) <= 3);
 
+  // In some cases,acpibutton can be mistaken for a keyboard and freeze the keyboard when tring grab.
+  if (is_acpibutton) {
+    if (verbose)
+      printf("Do Not grab acpibutton: %s\n", libevdev_get_name(evdev));
+    is_keyboard = false;
+  }
+  // In some cases,tring grab "Logitech USB Receiver Keyboard" will freeze the keyboard.
+  if (is_likekeyboard) {
+    if (verbose)
+      printf("Do Not grab likekeyboard: %s,version: %d,bustype: %d\n", libevdev_get_name(evdev), libevdev_get_id_version(evdev), libevdev_get_id_bustype(evdev));
+    is_keyboard = false;
+  }
+
   if (is_accelerometer) {
     if (verbose)
       printf("Ignoring accelerometer: %s\n", name);
@@ -850,6 +922,13 @@ void evdev_create(const char* device, struct mapping* 
   }
 
   if (is_gamepad) {
+    if (!isNoSdl) {
+      if (verbose)
+        printf("Gamepad %s ignored,use sdl instead.\n", name);
+      libevdev_free(evdev);
+      close(fd);
+      return;
+    }
     evdev_gamepads++;
 
     if (mappings == NULL) {
@@ -1054,11 +1133,7 @@ void evdev_start() {
   // code looks for. For this reason, we wait to grab until
   // we're ready to take input events. Ctrl+C works up until
   // this point.
-  for (int i = 0; i < numDevices; i++) {
-    if ((devices[i].is_keyboard || devices[i].is_mouse || devices[i].is_touchscreen) && ioctl(devices[i].fd, EVIOCGRAB, 1) < 0) {
-      fprintf(stderr, "EVIOCGRAB failed with error %d\n", errno);
-    }
-  }
+  grab_window(true);
 
   // Any new input devices detected after this point will be grabbed immediately
   grabbingDevices = true;
@@ -1111,4 +1186,23 @@ void evdev_rumble(unsigned short controller_id, unsign
   event.value = 1;
   write(device->fd, (const void*) &event, sizeof(event));
   device->haptic_effect_id = effect.id;
+}
+
+void grab_window(bool grabstat) {
+  if (grabstat != iskeyboardgrab) {
+    int grabnum;
+    if (iskeyboardgrab) {
+      grabnum = 0;
+      iskeyboardgrab = false;
+    } else {
+      grabnum = 1;
+      iskeyboardgrab = true;
+    }
+    for (int i = 0; i < numDevices; i++) {
+      if (devices[i].is_keyboard || devices[i].is_mouse || devices[i].is_touchscreen) {
+        if (ioctl(devices[i].fd, EVIOCGRAB, grabnum) < 0)
+          fprintf(stderr, "EVIOCGRAB failed with error %d\n", errno);
+      }
+    }
+  }
 }
