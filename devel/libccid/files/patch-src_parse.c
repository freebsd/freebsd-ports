--- src/parse.c.orig	2009-03-07 20:07:07.000000000 +0300
+++ src/parse.c	2009-03-07 20:09:07.000000000 +0300
@@ -46,6 +46,7 @@
 
 static int ccid_parse_interface_descriptor(usb_dev_handle *handle,
 	struct usb_device *dev);
+struct usb_interface * get_ccid_usb_interface(struct usb_device *dev);
 
 
 /*****************************************************************************
