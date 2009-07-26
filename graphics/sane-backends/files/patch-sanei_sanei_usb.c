--- sanei/sanei_usb.c.orig	2009-07-26 21:29:33.000000000 +0200
+++ sanei/sanei_usb.c	2009-07-26 21:31:42.000000000 +0200
@@ -96,7 +96,8 @@
 }
 #endif /* HAVE_USBCALLS */
 
-#if defined (__FreeBSD__) 
+#if (defined (__FreeBSD__) && (__FreeBSD_version < 800064))
+#include <sys/param.h>
 #include <dev/usb/usb.h>
 #endif /* __FreeBSD__ */
 #if defined (__DragonFly__)
@@ -273,7 +274,7 @@
     *vendorID = vendor;
     *productID = product;
   }
-#elif defined (__FreeBSD__) || defined (__DragonFly__)
+#elif (defined (__FreeBSD__) && __FreeBSD_version < 800064) || defined (__DragonFly__)
   {
     int controller;
     int ctrl_fd;
