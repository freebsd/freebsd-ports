--- app/src/version.c.orig	2025-03-29 15:15:14 UTC
+++ app/src/version.c
@@ -8,7 +8,7 @@
 # include <libavdevice/avdevice.h>
 #endif
 #ifdef HAVE_USB
-# include <libusb-1.0/libusb.h>
+# include <libusb.h>
 #endif
 #include <SDL2/SDL_version.h>
 
