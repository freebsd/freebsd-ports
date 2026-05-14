--- app/src/version.c.orig	2026-05-12 19:35:47 UTC
+++ app/src/version.c
@@ -8,7 +8,7 @@
 # include <libavdevice/avdevice.h>
 #endif
 #ifdef HAVE_USB
-# include <libusb-1.0/libusb.h>
+# include <libusb.h>
 #endif
 #include <SDL3/SDL_version.h>
 
