--- src/freeglut_joystick.c.orig	2011-09-28 03:37:26.000000000 +0200
+++ src/freeglut_joystick.c	2012-01-05 09:51:03.000000000 +0100
@@ -152,7 +152,10 @@
 #                include <libusbhid.h>
 #            endif
 #        endif
-#        include <legacy/dev/usb/usb.h>
+#        include <dev/usb/usb.h>
+#        if __FreeBSD_version >= 800061
+#            include <dev/usb/usb_ioctl.h>
+#        endif
 #        include <dev/usb/usbhid.h>
 
 /* Compatibility with older usb.h revisions */
@@ -199,6 +202,7 @@
  */
 static char *fghJoystickWalkUSBdev(int f, char *dev, char *out, int outlen)
 {
+#if __FreeBSD_version < 800061
   struct usb_device_info di;
   int i, a;
   char *cp;
@@ -220,6 +224,7 @@
         return out;
       }
   }
+#endif
   return NULL;
 }
 
