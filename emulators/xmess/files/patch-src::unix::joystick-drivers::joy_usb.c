--- src/unix/joystick-drivers/joy_usb.c.orig	Sat Nov  3 02:22:56 2001
+++ src/unix/joystick-drivers/joy_usb.c	Thu Oct 31 15:27:02 2002
@@ -23,8 +23,12 @@
 #if defined(__ARCH_netbsd)
 #include <usb.h>
 #elif defined(__ARCH_freebsd)
+#ifdef HAVE_USBHID_H
+#include <libusbhid.h>
+#else
 #include <libusb.h>
 #endif
+#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -82,7 +86,22 @@
 
   priv_joy_data[i].hids = NULL;
 
+#if defined(__ARCH_freebsd) && __FreeBSD_version > 500000
+  if (ioctl(joy_data[i].fd, USB_GET_REPORT_ID, &report_id) < 0)
+    {
+      fprintf(stderr_file, "error: /dev/uhid%d: %s", i, strerror(errno));
+      return FALSE;
+    }
+#endif
+
+#if defined(__ARCH_freebsd) && defined(HAVE_USBHID_H)
+  size = hid_report_size(rd, hid_input, report_id);
+  priv_joy_data[i].offset = 0;
+#else
   size = hid_report_size(rd, hid_input, &report_id);
+  priv_joy_data[i].offset = (report_id != 0);
+#endif
+
   if ((priv_joy_data[i].data_buf = malloc(size)) == NULL)
     {
       fprintf(stderr_file, "error: couldn't malloc %d bytes\n", size);
@@ -90,7 +109,6 @@
       return FALSE;
     }
   priv_joy_data[i].dlen = size;
-  priv_joy_data[i].offset = (report_id != 0);
 
   is_joystick = 0;
   for (d = hid_start_parse(rd, 1 << hid_input); hid_get_item(d, &h); )
