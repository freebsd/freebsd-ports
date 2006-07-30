--- bsd.c.orig	Sun Jul 30 11:18:07 2006
+++ bsd.c	Sun Jul 30 11:20:30 2006
@@ -623,9 +623,21 @@
 
 int usb_clear_halt(usb_dev_handle *dev, unsigned int ep)
 {
-  /* Not yet done, because I haven't needed it. */
+  int ret;
+  struct usb_ctl_request ctl_req;
 
-  USB_ERROR_STR(-ENOSYS, "usb_clear_halt called, unimplemented on BSD");
+  ctl_req.ucr_addr = 0; // Not used for this type of request
+  ctl_req.ucr_request.bmRequestType = UT_WRITE_ENDPOINT;
+  ctl_req.ucr_request.bRequest = UR_CLEAR_FEATURE;
+  USETW(ctl_req.ucr_request.wValue, UF_ENDPOINT_HALT);
+  USETW(ctl_req.ucr_request.wIndex, ep);
+  USETW(ctl_req.ucr_request.wLength, 0);
+  ctl_req.ucr_flags = 0;
+
+  if ((ret = ioctl(dev->fd, USB_DO_REQUEST, &ctl_req)) < 0)
+      USB_ERROR_STR(-errno, "clear_halt:  failed for %d", ep);
+
+  return ret;
 }
 
 int usb_reset(usb_dev_handle *dev)
