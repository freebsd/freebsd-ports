--- tests/testlibusb.c	2021-11-30 22:59:53.050103000 -0500
+++ tests/testlibusb.c	2021-11-30 23:03:26.187330000 -0500
@@ -113,7 +113,9 @@
     printf("      wSpeedSupported:       %u\n", ss_usb_cap->wSpeedSupported);
     printf("      bFunctionalitySupport: %u\n", ss_usb_cap->bFunctionalitySupport);
     printf("      bU1devExitLat:         %u\n", ss_usb_cap->bU1DevExitLat);
+#if !defined(__FreeBSD__)
     printf("      bU2devExitLat:         %u\n", ss_usb_cap->bU2DevExitLat);
+#endif
 }
 
 static void print_bos(libusb_device_handle *handle)
@@ -131,6 +133,7 @@
 
     printf("  Binary Object Store (BOS):\n");
     printf("    wTotalLength:            %u\n", bos->wTotalLength);
+#if !defined(__FreeBSD__)
     printf("    bNumDeviceCaps:          %u\n", bos->bNumDeviceCaps);
 
     for (i = 0; i < bos->bNumDeviceCaps; i++)
@@ -168,7 +171,7 @@
             libusb_free_ss_usb_device_capability_descriptor(ss_dev_cap);
         }
     }
-
+#endif
     libusb_free_bos_descriptor(bos);
 }
 
