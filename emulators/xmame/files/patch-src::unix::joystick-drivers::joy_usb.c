--- src/unix/joystick-drivers/joy_usb.c.orig	Fri May  3 02:53:54 2002
+++ src/unix/joystick-drivers/joy_usb.c	Thu Oct 31 13:17:45 2002
@@ -27,8 +27,12 @@
 #include <usb.h>
 #endif
 #elif defined(__ARCH_freebsd)
+#ifdef HAVE_USBHID_H
+#include <libusbhid.h>
+#else
 #include <libusb.h>
 #endif
+#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -87,11 +91,13 @@
   priv_joy_data[i].hids = NULL;
 
 #ifdef HAVE_USBHID_H
+#if defined(__ARCH_netbsd) || (defined(__ARCH_freebsd) && __FreeBSD_version > 500000)
   if (ioctl(joy_data[i].fd, USB_GET_REPORT_ID, &report_id) < 0)
     {
       fprintf(stderr_file, "error: /dev/uhid%d: %s", i, strerror(errno));
       return FALSE;
     }
+#endif
 
   size = hid_report_size(rd, hid_input, report_id);
   priv_joy_data[i].offset = 0;
@@ -108,7 +114,7 @@
   priv_joy_data[i].dlen = size;
 
   is_joystick = 0;
-#ifdef HAVE_USBHID_H
+#if defined(__ARCH_netbsd) && defined(HAVE_USBHID_H)
   for (d = hid_start_parse(rd, 1 << hid_input, report_id);
        hid_get_item(d, &h); )
 #else
