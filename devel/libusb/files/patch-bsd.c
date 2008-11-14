--- bsd.c.orig	2006-03-04 03:52:46.000000000 +0100
+++ bsd.c	2008-11-03 00:08:15.000000000 +0100
@@ -408,7 +408,7 @@
   /* Ensure the endpoint address is correct */
   ep |= USB_ENDPOINT_IN;
 
-  fd = ensure_ep_open(dev, ep, O_RDONLY);
+  fd = ensure_ep_open(dev, ep, O_RDONLY | O_NONBLOCK);
   if (fd < 0) {
     if (usb_debug >= 2) {
 #ifdef __FreeBSD_kernel__
@@ -477,7 +477,7 @@
     USB_ERROR_STR(-errno, "error sending control message: %s",
                   strerror(errno));
 
-  return UGETW(req.ucr_request.wLength);
+  return req.ucr_actlen;
 }
 
 int usb_os_find_busses(struct usb_bus **busses)
@@ -623,9 +623,21 @@
 
 int usb_clear_halt(usb_dev_handle *dev, unsigned int ep)
 {
-  /* Not yet done, because I haven't needed it. */
+  int ret;
+  struct usb_ctl_request ctl_req;
+
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
 
-  USB_ERROR_STR(-ENOSYS, "usb_clear_halt called, unimplemented on BSD");
+  return ret;
 }
 
 int usb_reset(usb_dev_handle *dev)
