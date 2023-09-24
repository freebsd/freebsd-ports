--- src/input/evdev.c.orig	2023-09-01 23:40:56 UTC
+++ src/input/evdev.c
@@ -38,10 +38,12 @@
 #include <limits.h>
 #include <unistd.h>
 #include <pthread.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <math.h>
 
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+bool iskeyboardgrab = true;
+
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 #define int16_to_le(val) val
 #else
 #define int16_to_le(val) ((((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00))
@@ -66,8 +68,8 @@ struct input_device {
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
@@ -343,7 +345,7 @@ static bool evdev_handle_event(struct input_event *ev,
     if (dev->mouseHScroll != 0) {
       LiSendHScrollEvent(dev->mouseHScroll);
       dev->mouseHScroll = 0;
-    }
+    } 
     if (dev->gamepadModified) {
       if (dev->controllerId < 0) {
         for (int i = 0; i < MAX_GAMEPADS; i++) {
@@ -813,7 +815,7 @@ void evdev_create(const char* device, struct mapping* 
   if (mappings == NULL && strstr(name, "Xbox 360 Wireless Receiver") != NULL)
     mappings = xwc_mapping;
 
-  bool is_keyboard = libevdev_has_event_code(evdev, EV_KEY, KEY_Q);
+  bool is_keyboard = libevdev_has_event_code(evdev, EV_KEY, KEY_Q) && libevdev_get_id_version(evdev) < 500;
   bool is_mouse = libevdev_has_event_type(evdev, EV_REL) || libevdev_has_event_code(evdev, EV_KEY, BTN_LEFT);
   bool is_touchscreen = libevdev_has_event_code(evdev, EV_KEY, BTN_TOUCH);
 
@@ -1055,8 +1057,12 @@ void evdev_start() {
   // we're ready to take input events. Ctrl+C works up until
   // this point.
   for (int i = 0; i < numDevices; i++) {
-    if ((devices[i].is_keyboard || devices[i].is_mouse || devices[i].is_touchscreen) && ioctl(devices[i].fd, EVIOCGRAB, 1) < 0) {
+    if ((devices[i].is_mouse || devices[i].is_touchscreen) && ioctl(devices[i].fd, EVIOCGRAB, 1) < 0) {
       fprintf(stderr, "EVIOCGRAB failed with error %d\n", errno);
+    }
+    if (devices[i].is_keyboard && libevdev_get_id_bustype(devices[i].dev) > 3) {
+      if (ioctl(devices[i].fd, EVIOCGRAB, 1) < 0)
+        fprintf(stderr, "EVIOCGRAB failed with error %d\n", errno);
     }
   }
 
