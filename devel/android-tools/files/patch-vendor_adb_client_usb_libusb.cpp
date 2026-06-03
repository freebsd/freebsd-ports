--- vendor/adb/client/usb_libusb.cpp.orig	2024-08-29 19:46:57.000000000 +0200
+++ vendor/adb/client/usb_libusb.cpp	2026-04-13 19:58:23.616588000 +0200
@@ -38,6 +38,8 @@
 
 #ifdef ANDROID_TOOLS_USE_BUNDLED_LIBUSB
 #include <libusb/libusb.h>
+#elif defined(__FreeBSD__)
+#include <libusb.h>
 #else
 #include <libusb-1.0/libusb.h>
 #endif
@@ -507,8 +509,10 @@
                 return 5000;
             case LIBUSB_SPEED_SUPER_PLUS:
                 return 10000;
+#ifdef LIBUSB_SPEED_SUPER_PLUS_X2
             case LIBUSB_SPEED_SUPER_PLUS_X2:
                 return 20000;
+#endif
             case LIBUSB_SPEED_UNKNOWN:
             default:
                 return 0;
@@ -526,20 +530,23 @@
             msb++;
         }
 
-        switch (1 << msb) {
-            case LIBUSB_LOW_SPEED_OPERATION:
+        // Use literal values from 'enum libusb_supported_speed' (USB spec defined bits)
+        // to remain portable across libusb implementations that may not expose the enum.
+        switch (1 << msb) {
+            case (1 << 0):  // LIBUSB_LOW_SPEED_OPERATION
                 return 1;
-            case LIBUSB_FULL_SPEED_OPERATION:
+            case (1 << 1):  // LIBUSB_FULL_SPEED_OPERATION
                 return 12;
-            case LIBUSB_HIGH_SPEED_OPERATION:
+            case (1 << 2):  // LIBUSB_HIGH_SPEED_OPERATION
                 return 480;
-            case LIBUSB_SUPER_SPEED_OPERATION:
+            case (1 << 3):  // LIBUSB_SUPER_SPEED_OPERATION
                 return 5000;
             default:
                 return 0;
         }
     }
 
+#ifdef LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY
     static uint64_t ExtractMaxSuperSpeedPlus(libusb_ssplus_usb_device_capability_descriptor* cap) {
         // The exponents is one of {bytes, kB, MB, or GB}. We express speed in MB so we use a 0
         // multiplier for value which would result in 0MB anyway.
@@ -552,6 +559,7 @@
         }
         return max_speed;
     }
+#endif
 
     void RetrieveSpeeds() {
         negotiated_speed_ = ToConnectionSpeed(libusb_get_device_speed(device_.get()));
@@ -563,7 +571,9 @@
             return;
         }
 
-        for (int i = 0; i < bos->bNumDeviceCaps; i++) {
+        // Use bNumDeviceCapabilities for portability: on FreeBSD < 15 the field has
+        // this name; on FreeBSD >= 15 and upstream libusb it is a macro alias.
+        for (int i = 0; i < bos->bNumDeviceCapabilities; i++) {
             switch (bos->dev_capability[i]->bDevCapabilityType) {
                 case LIBUSB_BT_SS_USB_DEVICE_CAPABILITY: {
                     libusb_ss_usb_device_capability_descriptor* cap = nullptr;
@@ -574,6 +584,7 @@
                         libusb_free_ss_usb_device_capability_descriptor(cap);
                     }
                 } break;
+#ifdef LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY
                 case LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY: {
                     libusb_ssplus_usb_device_capability_descriptor* cap = nullptr;
                     if (!libusb_get_ssplus_usb_device_capability_descriptor(
@@ -582,6 +593,7 @@
                         libusb_free_ssplus_usb_device_capability_descriptor(cap);
                     }
                 } break;
+#endif
                 default:
                     break;
             }
