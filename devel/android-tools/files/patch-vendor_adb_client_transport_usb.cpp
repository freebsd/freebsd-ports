--- vendor/adb/client/transport_usb.cpp.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/adb/client/transport_usb.cpp
@@ -180,6 +180,8 @@
     bool enable = false;
 #if defined(__APPLE__)
     enable = true;
+#elif defined(__FreeBSD__)
+    enable = true;
 #endif
     char* env = getenv("ADB_LIBUSB");
     if (env) {
