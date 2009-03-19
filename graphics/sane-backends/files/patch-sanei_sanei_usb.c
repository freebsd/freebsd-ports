--- sanei/sanei_usb.c.orig	2009-03-18 17:05:03.000000000 -0700
+++ sanei/sanei_usb.c	2009-03-18 17:05:06.000000000 -0700
@@ -88,6 +88,7 @@
 #endif /* HAVE_USBCALLS */
 
 #if defined (__FreeBSD__) 
+#include <sys/param.h>
 #include <dev/usb/usb.h>
 #endif /* __FreeBSD__ */
 #if defined (__DragonFly__)
@@ -252,7 +253,7 @@
     *vendorID = vendor;
     *productID = product;
   }
-#elif defined (__FreeBSD__) || defined (__DragonFly__)
+#elif (defined (__FreeBSD__) && __FreeBSD_version < 800064) || defined (__DragonFly__)
   {
     int controller;
     int ctrl_fd;
