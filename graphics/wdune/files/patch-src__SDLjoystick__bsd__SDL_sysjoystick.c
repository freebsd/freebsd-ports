--- src/SDLjoystick/bsd/SDL_sysjoystick.c.orig	2020-07-15 22:53:38 UTC
+++ src/SDLjoystick/bsd/SDL_sysjoystick.c
@@ -41,9 +41,6 @@ static char rcsid =
 
 #include "mysnprintf.h"
 
-#if defined(HAVE_USB_H)
-#include <usb.h>
-#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -53,8 +50,17 @@ static char rcsid =
 #include <libusb.h>
 #elif defined(HAVE_LIBUSBHID_H)
 #include <libusbhid.h>
+#elif defined(HAVE_USB_H)
+#include <usb.h>
 #endif
 
+#ifdef __FREEBSD__
+#ifndef __DragonFly__
+#include <osreldate.h>
+#endif
+#include <sys/joystick.h>
+#endif
+
 #include "SDL_error.h"
 #include "SDL_joystick.h"
 #include "SDL_sysjoystick.h"
@@ -64,6 +70,13 @@ static char rcsid =
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
@@ -120,7 +133,7 @@ static char *joydevnames[MAX_JOYS];
 static int report_alloc(struct report *, struct report_desc *, int);
 static void report_free(struct report *);
 
-#ifdef USBHID_UCR_DATA
+#if defined(USBHID_UCR_DATA) || (defined(__FREEBSD__) && (__FreeBSD_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
 #else
 #define REP_BUF_DATA(rep) ((rep)->buf->data)
@@ -132,7 +145,7 @@ SDL_SYS_JoystickInit(void)
     char s[16];
     int i, fd;
 
-    SDL_numjoysticks = 0;
+    int SDL_numjoysticks = 0;
 
     memset(joynames, NULL, sizeof(joynames));
     memset(joydevnames, NULL, sizeof(joydevnames));
