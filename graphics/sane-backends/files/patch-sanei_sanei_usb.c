--- sanei/sanei_usb.c.orig	Sun Apr 20 23:55:43 2003
+++ sanei/sanei_usb.c	Tue May 27 12:19:51 2003
@@ -59,6 +59,10 @@
 #include <usb.h>
 #endif /* HAVE_LIBUSB */
 
+#if defined (__FreeBSD__)
+#include <dev/usb/usb.h>
+#endif /* __FreeBSD__ */
+
 #define BACKEND_NAME	sanei_usb
 #include "../include/sane/sane.h"
 #include "../include/sane/sanei_debug.h"
@@ -177,6 +181,49 @@
     }
 }
 
+#if defined (__FreeBSD__)
+static void
+kernel_get_vendor_product (int fd, const char *name, int *vendorID, int *productID)
+{
+  int controller;
+  int ctrl_fd;
+  char buf[40];
+  int dev;
+
+  for (controller = 0; ; controller++ )
+    {
+      snprintf (buf, sizeof( buf ) - 1, "/dev/usb%d", controller);
+      ctrl_fd = open (buf, O_RDWR);
+
+      /* If we can not open the usb controller device, treat it
+        as the end of controller devices */
+      if (ctrl_fd < 0)
+	break;
+
+      /* Search for the scanner device on this bus */
+      for( dev = 1; dev < USB_MAX_DEVICES; dev++ )
+	{  
+	struct usb_device_info devInfo;
+	devInfo.udi_addr = dev;
+ 
+	if (ioctl (ctrl_fd, USB_DEVICEINFO, &devInfo) == -1)
+	  break; /* Treak this as the end of devices for this controller */
+
+	snprintf( buf, sizeof( buf ), "/dev/%s", devInfo.udi_devnames[0] );
+	if( strncmp( buf, name, sizeof( buf ) ) == 0 )
+	  {
+	    *vendorID = (int)devInfo.udi_vendorNo;
+	    *productID = (int)devInfo.udi_productNo;
+	    close( ctrl_fd );
+	    return;
+	  }
+	}
+      close( ctrl_fd );
+      DBG (3, "kernel_get_vendor_product: Could not retrieve "
+	  "vendor/product ID from device %d\n", fd );
+    }
+}
+#else
 static void
 kernel_get_vendor_product (int fd, int *vendorID, int *productID)
 {
@@ -197,6 +244,7 @@
 #endif /* defined (__linux__) */
       /* put more os-dependant stuff ... */
 }
+#endif
 
 void
 sanei_usb_init (void)
@@ -277,7 +325,11 @@
 		}
 	      vendor = -1;
 	      product = -1;
+#if defined (__FreeBSD__)
+	      kernel_get_vendor_product (fd, devname, &vendor, &product);
+#else
 	      kernel_get_vendor_product (fd, &vendor, &product);
+#endif
 	      close (fd);
 	      devices[dn].devname = strdup (devname);
 	      if (!devices[dn].devname)
@@ -440,7 +492,11 @@
     }
 
   if (devices[dn].method == sanei_usb_method_scanner_driver)
+#if defined (__FreeBSD__)
+    kernel_get_vendor_product (devices[dn].fd, devices[dn].devname, &vendorID, &productID);
+#else
     kernel_get_vendor_product (devices[dn].fd, &vendorID, &productID);
+#endif
   else if (devices[dn].method == sanei_usb_method_libusb)
     {
 #ifdef HAVE_LIBUSB

