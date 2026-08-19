--- vendor/adb/client/usb_libusb_hotplug.cpp.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/adb/client/usb_libusb_hotplug.cpp
@@ -37,6 +37,8 @@
 
 #ifdef ANDROID_TOOLS_USE_BUNDLED_LIBUSB
 #include "libusb/libusb.h"
+#elif defined(__FreeBSD__)
+#include <libusb.h>
 #else
 #include <libusb-1.0/libusb.h>
 #endif
@@ -228,7 +230,7 @@
             static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
                                               LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT),
             LIBUSB_HOTPLUG_ENUMERATE, LIBUSB_HOTPLUG_MATCH_ANY, LIBUSB_HOTPLUG_MATCH_ANY,
-            LIBUSB_HOTPLUG_MATCH_ANY, hotplug_callback, nullptr, nullptr);
+            LIBUSB_CLASS_PER_INTERFACE, hotplug_callback, nullptr, nullptr);
 
     if (rc != LIBUSB_SUCCESS) {
         LOG(FATAL) << "failed to register libusb hotplug callback";
