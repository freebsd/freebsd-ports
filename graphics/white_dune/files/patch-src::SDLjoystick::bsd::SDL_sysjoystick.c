--- src/SDLjoystick/bsd/SDL_sysjoystick.c.orig	Tue Nov 25 01:30:44 2003
+++ src/SDLjoystick/bsd/SDL_sysjoystick.c	Tue Nov 25 21:30:52 2003
@@ -39,9 +39,6 @@
 #include <string.h>
 #include <errno.h>
 
-#if defined(HAVE_USB_H)
-#include <usb.h>
-#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 
@@ -51,6 +48,8 @@
 #include <libusb.h>
 #elif defined(HAVE_LIBUSBHID_H)
 #include <libusbhid.h>
+#elif defined(HAVE_USB_H)
+#include <usb.h>
 #endif
 
 #include "SDL_error.h"
