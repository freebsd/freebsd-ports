--- src/input/evdev.c.orig	2021-12-20 00:24:48 UTC
+++ src/input/evdev.c
@@ -38,10 +38,10 @@
 #include <limits.h>
 #include <unistd.h>
 #include <pthread.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <math.h>
 
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 #define int16_to_le(val) val
 #else
 #define int16_to_le(val) ((((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00))
@@ -66,8 +66,8 @@ struct input_device {
   int hats_state[3][2];
   int fd;
   char modifiers;
-  __s32 mouseDeltaX, mouseDeltaY, mouseScroll;
-  __s32 touchDownX, touchDownY, touchX, touchY;
+  int32_t mouseDeltaX, mouseDeltaY, mouseScroll;
+  int32_t touchDownX, touchDownY, touchX, touchY;
   struct timeval touchDownTime;
   struct timeval btnDownTime;
   short controllerId;
