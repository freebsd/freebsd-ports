--- adb/transport_usb.cpp.orig	2018-06-21 00:58:42 UTC
+++ adb/transport_usb.cpp
@@ -186,6 +186,8 @@ int is_adb_interface(int usb_class, int usb_subclass, 
 bool should_use_libusb() {
 #if !ADB_HOST
     return false;
+#elif !defined(__linux__) && !defined(__APPLE__) && !defined(_WIN32)
+    return true;
 #else
     static bool enable = getenv("ADB_LIBUSB") && strcmp(getenv("ADB_LIBUSB"), "1") == 0;
     return enable;
