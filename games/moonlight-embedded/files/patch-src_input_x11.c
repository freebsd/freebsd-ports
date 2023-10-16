--- src/input/x11.c.orig	2023-10-08 02:12:37 UTC
+++ src/input/x11.c
@@ -33,6 +33,8 @@
 
 #define ACTION_MODIFIERS (MODIFIER_SHIFT|MODIFIER_ALT|MODIFIER_CTRL)
 #define QUIT_KEY 0x18  /* KEY_Q */
+#define GRAB_KEY 0x34  /* KEY_Z */
+#define TAB_KEY 0x17  /* KEY_Tab */
 
 static Display *display;
 static Window window;
@@ -46,6 +48,35 @@ static const char data[1] = {0};
 static Cursor cursor;
 static bool grabbed = True;
 
+static bool isgrabkeyrelease = false;
+static bool waitingToSwitchGrabOnModifierUp = false;
+static bool waitingToExitOnModifiersUp = false;
+extern bool iskeyboardgrab;
+extern void grab_window(bool grabstat);
+
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
+      LiSendKeyboardEvent(0x80 << 8 | keyCodes[i - 8], KEY_ACTION_UP, 0);
+    }
+  }
+}
+static void clearallkey () {
+  for (int i=0;i<0xFF;i++) {
+    if (keystatlist[i] == 1) {
+      keystatlist[i] = 0;
+    }
+  }
+}
+
 static int x11_handler(int fd) {
   XEvent event;
   int button = 0;
@@ -54,18 +85,24 @@ static int x11_handler(int fd) {
   while (XPending(display)) {
     XNextEvent(display, &event);
     switch (event.type) {
+    case FocusIn:
+    case FocusOut:
+      if (event.type == FocusIn) {
+        clearallkey();
+        keyboard_modifiers = 0;
+        grabbed = true;
+      } else {
+        if (iskeyboardgrab)
+          break;
+        freeallkey();
+        keyboard_modifiers = 0;
+        grabbed = false;
+      }
+      XDefineCursor(display, window, grabbed ? cursor : 0);
+      break;
     case KeyPress:
     case KeyRelease:
       if (event.xkey.keycode >= 8 && event.xkey.keycode < (sizeof(keyCodes)/sizeof(keyCodes[0]) + 8)) {
-        if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event.type == KeyRelease) {
-          if (event.xkey.keycode == QUIT_KEY)
-            return LOOP_RETURN;
-          else {
-            grabbed = !grabbed;
-            XDefineCursor(display, window, grabbed ? cursor : 0);
-          }
-        }
-
         int modifier = 0;
         switch (event.xkey.keycode) {
         case 0x32:
@@ -89,8 +126,58 @@ static int x11_handler(int fd) {
             keyboard_modifiers &= ~modifier;
         }
 
+        if ((keyboard_modifiers & ACTION_MODIFIERS) == ACTION_MODIFIERS && event.type == KeyPress) {
+          if (event.xkey.keycode == QUIT_KEY) {
+            waitingToExitOnModifiersUp = true;
+            break;
+          } else if (event.xkey.keycode == GRAB_KEY) {
+            if (event.type == KeyPress) {
+              waitingToSwitchGrabOnModifierUp = true;
+              break;
+            }
+          }
+        }
+        if (waitingToSwitchGrabOnModifierUp) {
+          if (event.xkey.keycode == GRAB_KEY && event.type == KeyRelease) {
+            isgrabkeyrelease = true;
+            if (keyboard_modifiers != 0)
+              break;
+          }
+          if (keyboard_modifiers == 0 && isgrabkeyrelease) {
+            waitingToSwitchGrabOnModifierUp = false;
+            isgrabkeyrelease = false;
+            XDefineCursor(display, window, cursor);
+            freeallkey();
+            grab_window(true);
+            break;
+          }
+        } else if (waitingToExitOnModifiersUp) {
+          if (event.xkey.keycode == QUIT_KEY) {
+            if (keyboard_modifiers != 0)
+              break;
+          }
+          if (keyboard_modifiers == 0) {
+            freeallkey();
+            waitingToExitOnModifiersUp = false;
+            return LOOP_RETURN;
+          }
+        }
+        if (event.xkey.keycode == TAB_KEY && keyboard_modifiers == MODIFIER_ALT) {
+          freeallkey();
+          keyboard_modifiers = 0;
+          break;
+        }
+        if (event.xkey.keycode == 0x40 || event.xkey.keycode == 0x6c)
+          break;
+
+        if (event.type == KeyPress)
+            keypress(event.xkey.keycode);
+        else
+            keyrelease(event.xkey.keycode);
+
         short code = 0x80 << 8 | keyCodes[event.xkey.keycode - 8];
-        LiSendKeyboardEvent(code, event.type == KeyPress ? KEY_ACTION_DOWN : KEY_ACTION_UP, keyboard_modifiers);
+        if (!iskeyboardgrab)
+          LiSendKeyboardEvent(code, event.type == KeyPress ? KEY_ACTION_DOWN : KEY_ACTION_UP, keyboard_modifiers);
       }
       break;
     case ButtonPress:
@@ -106,16 +193,20 @@ static int x11_handler(int fd) {
         button = BUTTON_RIGHT;
         break;
       case Button4:
-        LiSendScrollEvent(1);
+        if (!iskeyboardgrab)
+          LiSendScrollEvent(1);
         break;
       case Button5:
-        LiSendScrollEvent(-1);
+        if (!iskeyboardgrab)
+          LiSendScrollEvent(-1);
         break;
       case 6:
-        LiSendHScrollEvent(-1);
+        if (!iskeyboardgrab)
+          LiSendHScrollEvent(-1);
         break;
       case 7:
-        LiSendHScrollEvent(1);
+        if (!iskeyboardgrab)
+          LiSendHScrollEvent(1);
         break;
       case 8:
         button = BUTTON_X1;
@@ -125,14 +216,16 @@ static int x11_handler(int fd) {
         break;
       }
 
-      if (button != 0)
+      if (button != 0 && !iskeyboardgrab)
         LiSendMouseButtonEvent(event.type==ButtonPress ? BUTTON_ACTION_PRESS : BUTTON_ACTION_RELEASE, button);
       break;
     case MotionNotify:
+      if (!grabbed)
+        break;
       motion_x = event.xmotion.x - last_x;
       motion_y = event.xmotion.y - last_y;
       if (abs(motion_x) > 0 || abs(motion_y) > 0) {
-        if (last_x >= 0 && last_y >= 0)
+        if (last_x >= 0 && last_y >= 0 && !iskeyboardgrab)
           LiSendMouseMoveEvent(motion_x, motion_y);
 
         if (grabbed)
