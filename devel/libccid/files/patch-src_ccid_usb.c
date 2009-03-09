--- src/ccid_usb.c.orig	2009-03-07 20:05:04.000000000 +0300
+++ src/ccid_usb.c	2009-03-07 20:09:14.000000000 +0300
@@ -56,6 +56,8 @@
 
 #define BUS_DEVICE_STRSIZE 32
 
+EXTERNAL struct usb_interface * get_ccid_usb_interface(struct usb_device *dev);
+
 typedef struct
 {
 	usb_dev_handle *handle;
