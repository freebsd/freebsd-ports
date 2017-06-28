--- adb/transport_usb.cpp.orig	2017-06-20 10:50:27 UTC
+++ adb/transport_usb.cpp
@@ -191,6 +191,8 @@ int is_adb_interface(int usb_class, int usb_subclass, 
 bool should_use_libusb() {
 #if defined(_WIN32) || !ADB_HOST
     return false;
+#elif !defined(__linux__) && !defined(__APPLE__)
+    return true;
 #else
     static bool disable = getenv("ADB_LIBUSB") && strcmp(getenv("ADB_LIBUSB"), "0") == 0;
     return !disable;
