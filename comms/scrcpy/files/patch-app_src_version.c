--- app/src/version.c.orig	2022-06-30 04:29:39 UTC
+++ app/src/version.c
@@ -7,7 +7,7 @@
 # include <libavdevice/avdevice.h>
 #endif
 #ifdef HAVE_USB
-# include <libusb-1.0/libusb.h>
+# include <libusb.h>
 #endif
 
 void
