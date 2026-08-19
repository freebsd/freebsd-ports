--- vendor/adb/client/usb_libusb_device.cpp.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/adb/client/usb_libusb_device.cpp
@@ -30,6 +30,8 @@
 
 #ifdef ANDROID_TOOLS_USE_BUNDLED_LIBUSB
 #include <libusb/libusb.h>
+#elif defined(__FreeBSD__)
+#include <libusb.h>
 #else
 #include <libusb-1.0/libusb.h>
 #endif
@@ -368,10 +370,14 @@
             return 480;
         case LIBUSB_SPEED_SUPER:
             return 5000;
+#ifdef LIBUSB_SPEED_SUPER_PLUS
         case LIBUSB_SPEED_SUPER_PLUS:
             return 10000;
+#endif
+#ifdef LIBUSB_SPEED_SUPER_PLUS_X2
         case LIBUSB_SPEED_SUPER_PLUS_X2:
             return 20000;
+#endif
         case LIBUSB_SPEED_UNKNOWN:
         default:
             return 0;
@@ -390,19 +396,20 @@
     }
 
     switch (1 << msb) {
-        case LIBUSB_LOW_SPEED_OPERATION:
+        case (1 << 0):  // LIBUSB_LOW_SPEED_OPERATION
             return 1;
-        case LIBUSB_FULL_SPEED_OPERATION:
-            return 12;
-        case LIBUSB_HIGH_SPEED_OPERATION:
+        case (1 << 1):  // LIBUSB_FULL_SPEED_OPERATION
+            return 12;
+        case (1 << 2):  // LIBUSB_HIGH_SPEED_OPERATION
             return 480;
-        case LIBUSB_SUPER_SPEED_OPERATION:
+        case (1 << 3):  // LIBUSB_SUPER_SPEED_OPERATION
             return 5000;
         default:
             return 0;
     }
 }
 
+#ifdef LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY
 static uint64_t ExtractMaxSuperSpeedPlus(libusb_ssplus_usb_device_capability_descriptor* cap) {
     // The exponents is one of {bytes, kB, MB, or GB}. We express speed in MB so we use a 0
     // multiplier for value which would result in 0MB anyway.
@@ -415,6 +422,7 @@
     }
     return max_speed;
 }
+#endif
 
 void LibUsbDevice::RetrieveSpeeds() {
     negotiated_speed_ = ToConnectionSpeed(libusb_get_device_speed(device_));
@@ -426,7 +434,7 @@
         return;
     }
 
-    for (int i = 0; i < bos->bNumDeviceCaps; i++) {
+    for (int i = 0; i < bos->bNumDeviceCapabilities; i++) {
         switch (bos->dev_capability[i]->bDevCapabilityType) {
             case LIBUSB_BT_SS_USB_DEVICE_CAPABILITY: {
                 libusb_ss_usb_device_capability_descriptor* cap = nullptr;
@@ -436,6 +444,7 @@
                     libusb_free_ss_usb_device_capability_descriptor(cap);
                 }
             } break;
+#ifdef LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY
             case LIBUSB_BT_SUPERSPEED_PLUS_CAPABILITY: {
                 libusb_ssplus_usb_device_capability_descriptor* cap = nullptr;
                 if (!libusb_get_ssplus_usb_device_capability_descriptor(
@@ -444,6 +453,7 @@
                     libusb_free_ssplus_usb_device_capability_descriptor(cap);
                 }
             } break;
+#endif
             default:
                 break;
         }
