--- src/unix/joystick-drivers/joy_usb.c.orig	Mon Mar 17 22:36:59 2003
+++ src/unix/joystick-drivers/joy_usb.c	Tue Apr  8 22:54:47 2003
@@ -20,19 +20,27 @@
    "Patches to support other archs are welcome ;)"
 #endif
 
-#if defined(__ARCH_netbsd)
-#ifdef HAVE_USBHID_H
-#include <usbhid.h>
+#if defined(HAVE_USBHID_H) || defined(HAVE_LIBUSBHID_H)
+#	ifdef HAVE_USBHID_H
+#		include <usbhid.h>
+#	endif
+#	ifdef HAVE_LIBUSBHID_H
+#		include <libusbhid.h>
+#	endif
 #else
-#include <usb.h>
-#endif
-#elif defined(__ARCH_freebsd)
-#ifdef HAVE_USBHID_H
-#include <libusbhid.h>
-#else
-#include <libusb.h>
+#	ifdef __ARCH_netbsd
+#		include <usb.h>
+#	endif
+#	ifdef __ARCH_freebsd
+#		include <libusb.h>
+#	endif
 #endif
+
+#ifdef __ARCH_freebsd
+#include <osreldate.h>
+#include <sys/ioctl.h>
 #endif
+
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -90,7 +98,7 @@
 
   priv_joy_data[i].hids = NULL;
 
-#ifdef HAVE_USBHID_H
+#if defined(HAVE_USBHID_H) || defined(HAVE_LIBUSBHID_H)
 #if defined(__ARCH_netbsd) || (defined(__ARCH_freebsd) && __FreeBSD_version > 500000)
   if (ioctl(joy_data[i].fd, USB_GET_REPORT_ID, &report_id) < 0)
     {
@@ -114,7 +122,7 @@
   priv_joy_data[i].dlen = size;
 
   is_joystick = 0;
-#if defined(__ARCH_netbsd) && defined(HAVE_USBHID_H)
+#if defined(HAVE_USBHID_H)
   for (d = hid_start_parse(rd, 1 << hid_input, report_id);
        hid_get_item(d, &h); )
 #else
