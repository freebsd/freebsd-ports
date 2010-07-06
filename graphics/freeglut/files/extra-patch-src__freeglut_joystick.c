--- ./src/freeglut_joystick.c.orig	2009-11-14 06:31:39.000000000 +0200
+++ ./src/freeglut_joystick.c	2010-05-31 21:27:13.362358514 +0300
@@ -79,11 +79,13 @@
 #        include <errno.h>
 #    endif
 #    if defined(__FreeBSD__) || defined(__NetBSD__)
+#        include <osreldate.h>
 /* XXX The below hack is done until freeglut's autoconf is updated. */
 #        define HAVE_USB_JS    1
 
 #        if defined(__FreeBSD__)
 #            include <sys/joystick.h>
+#            include <dev/usb/usb_ioctl.h>
 #        else
 /*
  * XXX NetBSD/amd64 systems may find that they have to steal the
@@ -200,7 +202,7 @@
  */
 static char *fghJoystickWalkUSBdev(int f, char *dev, char *out, int outlen)
 {
-  struct usb_device_info di;
+/*  struct usb_device_info di;
   int i, a;
   char *cp;
 
@@ -221,6 +223,7 @@
         return out;
       }
   }
+  */
   return NULL;
 }
 

