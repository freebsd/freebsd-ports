--- tests/rigtestlibusb.c.orig	2025-07-18 18:31:35 UTC
+++ tests/rigtestlibusb.c
@@ -116,8 +116,12 @@ static void print_ss_usb_cap(const struct
     printf("      bmAttributes:          %02xh\n", ss_usb_cap->bmAttributes);
     printf("      wSpeedSupported:       %u\n", ss_usb_cap->wSpeedSupported);
     printf("      bFunctionalitySupport: %u\n", ss_usb_cap->bFunctionalitySupport);
-    printf("      bU1devExitLat:         %u\n", ss_usb_cap->bU1DevExitLat);
+    printf("      wU1devExitLat:         %u\n", ss_usb_cap->bU1DevExitLat);
+#ifdef __FreeBSD__
+    printf("      wU2devExitLat:         %u\n", ss_usb_cap->wU2DevExitLat);
+#else
     printf("      bU2devExitLat:         %u\n", ss_usb_cap->bU2DevExitLat);
+#endif
 }
 
 static void print_bos(libusb_device_handle *handle)
@@ -133,11 +137,17 @@ static void print_bos(libusb_device_handle *handle)
         return;
     }
 
+
     printf("  Binary Object Store (BOS):\n");
     printf("    wTotalLength:            %u\n", bos->wTotalLength);
+#ifdef __FreeBSD__
+    printf("    bNumDeviceCapabilities:          %u\n", bos->bNumDeviceCapabilities);
+    for (i = 0; i < bos->bNumDeviceCapabilities; i++)
+#else
     printf("    bNumDeviceCaps:          %u\n", bos->bNumDeviceCaps);
-
     for (i = 0; i < bos->bNumDeviceCaps; i++)
+#endif
+
     {
         struct libusb_bos_dev_capability_descriptor *dev_cap = bos->dev_capability[i];
 
@@ -172,7 +182,6 @@ static void print_bos(libusb_device_handle *handle)
             libusb_free_ss_usb_device_capability_descriptor(ss_dev_cap);
         }
     }
-
     libusb_free_bos_descriptor(bos);
 }
 
