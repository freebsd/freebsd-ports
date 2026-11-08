--- vendor/adb/client/usb_libusb_hotplug.h.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/adb/client/usb_libusb_hotplug.h
@@ -20,6 +20,8 @@
 
 #ifdef ANDROID_TOOLS_USE_BUNDLED_LIBUSB
 #include <libusb/libusb.h>
+#elif defined(__FreeBSD__)
+#include <libusb.h>
 #else
 #include <libusb-1.0/libusb.h>
 #endif
