--- usb_libusb.c.orig	2013-08-01 17:14:17.000000000 +0800
+++ usb_libusb.c	2013-08-01 17:14:46.000000000 +0800
@@ -37,7 +37,7 @@
 #define   TRACE_TAG  TRACE_USB
 #include "adb.h"
 
-static adb_mutex_t usb_lock = ADB_MUTEX_INITIALIZER;
+ADB_MUTEX_DEFINE( usb_lock );
 static libusb_context *ctx = NULL;
 
 struct usb_handle
@@ -347,7 +347,11 @@ register_device(struct usb_handle *uh, c
 
     adb_mutex_unlock(&usb_lock);
 
-    register_usb_transport(usb, serial, NULL, 1); 
+    char devpath[64];
+    snprintf(devpath, sizeof(devpath), "ugen%d.%d",
+             uh->dev_bus, uh->dev_addr);
+
+    register_usb_transport(usb, serial, devpath, 1);
 
     return (1);
 }
