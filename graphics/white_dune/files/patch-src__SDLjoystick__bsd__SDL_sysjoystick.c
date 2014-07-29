--- src/SDLjoystick/bsd/SDL_sysjoystick.c.orig	2010-12-09 13:36:53.000000000 +0600
+++ src/SDLjoystick/bsd/SDL_sysjoystick.c	2011-01-08 20:40:24.000000000 +0600
@@ -41,9 +41,6 @@
 
 #include "mysnprintf.h"
 
-#if defined(HAVE_USB_H)
-#include <usb.h>
-#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -53,6 +50,15 @@
 #include <libusb.h>
 #elif defined(HAVE_LIBUSBHID_H)
 #include <libusbhid.h>
+#elif defined(HAVE_USB_H)
+#include <usb.h>
+#endif
+
+#ifdef __FREEBSD__
+#ifndef __DragonFly__
+#include <osreldate.h>
+#endif
+#include <sys/joystick.h>
 #endif
 
 #include "SDL_error.h"
@@ -64,6 +70,13 @@
 #define MAX_JOY_JOYS 2
 #define MAX_JOYS (MAX_UHID_JOYS + MAX_JOY_JOYS)
 
+#if defined(__FREEBSD__) && (__FreeBSD_version > 800063)
+struct usb_ctl_report {
+	int ucr_report;
+	u_char ucr_data[1024]; /* filled data size will vary */
+    };
+#endif
+
 struct report {
     struct usb_ctl_report *buf;  /* Buffer */
     size_t size;  /* Buffer size */
@@ -120,7 +133,7 @@
 static int report_alloc(struct report *, struct report_desc *, int);
 static void report_free(struct report *);
 
-#ifdef USBHID_UCR_DATA
+#if defined(USBHID_UCR_DATA) || (defined(__FREEBSD__) && (__FreeBSD_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
 #else
 #define REP_BUF_DATA(rep) ((rep)->buf->data)
@@ -132,7 +145,7 @@
     char s[16];
     int i, fd;
 
-    SDL_numjoysticks = 0;
+    int SDL_numjoysticks = 0;
 
     memset(joynames, NULL, sizeof(joynames));
     memset(joydevnames, NULL, sizeof(joydevnames));
