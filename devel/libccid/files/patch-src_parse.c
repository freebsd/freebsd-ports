--- src/parse.c.orig	2009-04-02 17:52:07.000000000 +0200
+++ src/parse.c	2009-10-17 13:17:25.000000000 +0200
@@ -46,6 +46,7 @@
 
 static int ccid_parse_interface_descriptor(usb_dev_handle *handle,
 	struct usb_device *dev, int num);
+struct usb_interface * get_ccid_usb_interface(struct usb_device *dev, int *num);
 
 
 /*****************************************************************************
