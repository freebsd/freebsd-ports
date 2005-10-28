--- bsd.c.orig	Wed Feb 18 07:34:52 2004
+++ bsd.c	Thu Jun 16 22:08:00 2005
@@ -457,7 +457,7 @@
   USETW(req.ucr_request.wLength, size);
 
   req.ucr_data = bytes;
-  req.ucr_flags = 0;
+  req.ucr_flags = USBD_SHORT_XFER_OK;
 
   ret = ioctl(dev->fd, USB_SET_TIMEOUT, &timeout);
 #if (__NetBSD__ || __OpenBSD__)
