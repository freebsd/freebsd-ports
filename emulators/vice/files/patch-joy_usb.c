--- src/arch/unix/joy_usb.c.orig	2009-10-21 18:46:46.000000000 +0200
+++ src/arch/unix/joy_usb.c	2009-12-25 18:32:15.000000000 +0100
@@ -179,11 +179,9 @@
         found = 0;
         is_joy = 0;
 #if !defined(HAVE_USBHID_H) && !defined(HAVE_LIBUSB_H) && defined(HAVE_LIBUSBHID)
-        for (d = hid_start_parse(report, id) {
-        }
+        for (d = hid_start_parse(report, id);
 #else
-        for (d = hid_start_parse(report, 1 << hid_input, id) {
-        }
+        for (d = hid_start_parse(report, 1 << hid_input, id);
 #endif
         hid_get_item(d, &h);
         )
