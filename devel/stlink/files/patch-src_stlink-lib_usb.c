--- src/stlink-lib/usb.c.orig	2025-04-02 12:34:33 UTC
+++ src/stlink-lib/usb.c
@@ -1172,7 +1172,7 @@ stlink_t *stlink_open_usb(enum ugly_loglevel verbose, 
 
         if (ret) { continue; } // could not open device
 
-        uint32_t serial_len = stlink_serial(handle, &desc, sl->serial);
+        size_t serial_len = stlink_serial(handle, &desc, sl->serial);
 
         libusb_close(handle);
 
@@ -1375,7 +1375,7 @@ static uint32_t stlink_probe_usb_devs(libusb_device **
             break;
         }
 
-        uint32_t serial_len = stlink_serial(handle, &desc, serial);
+        size_t serial_len = stlink_serial(handle, &desc, serial);
 
         libusb_close(handle);
 
