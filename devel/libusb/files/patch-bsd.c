--- bsd.orig    Sun Mar  3 09:58:41 2002
+++ bsd.c       Sun Mar  3 10:03:56 2002
@@ -151,8 +151,8 @@
   if (dev->interface < 0)
     USB_ERROR(-EINVAL);
 
-  intf.interface_index = dev->interface;
-  intf.alt_no = alternate;
+  intf.uai_interface_index = dev->interface;
+  intf.uai_alt_no = alternate;
 
   ret = ioctl(dev->fd, USB_SET_ALTINTERFACE, &intf);
   if (ret < 0)
@@ -284,14 +284,14 @@
     fprintf(stderr, "usb_control_msg: %d %d %d %d %p %d %d\n",
             requesttype, request, value, index, bytes, size, timeout);
 
-  req.request.bmRequestType = requesttype;
-  req.request.bRequest = request;
-  USETW(req.request.wValue, value);
-  USETW(req.request.wIndex, index);
-  USETW(req.request.wLength, size);
+  req.ucr_request.bmRequestType = requesttype;
+  req.ucr_request.bRequest = request;
+  USETW(req.ucr_request.wValue, value);
+  USETW(req.ucr_request.wIndex, index);
+  USETW(req.ucr_request.wLength, size);
 
-  req.data = bytes;
-  req.flags = 0;
+  req.ucr_data = bytes;
+  req.ucr_flags = 0;
 
   ret = ioctl(dev->fd, USB_SET_TIMEOUT, &timeout);
   if (ret < 0)
@@ -303,7 +303,7 @@
     USB_ERROR_STR(ret, "error sending control message: %s",
                   strerror(errno));
 
-  return UGETW(req.request.wLength);
+  return UGETW(req.ucr_request.wLength);
 }
 
 int usb_find_devices_on_bus(struct usb_bus *bus)
@@ -321,18 +321,18 @@
     struct usb_device *dev;
     char buf[20];
 
-    di.addr = device;
+    di.udi_addr = device;
     if (ioctl(cfd, USB_DEVICEINFO, &di) < 0)
       continue;
 
     /* There's a device; is it one we should mess with? */
 
-    if (strncmp(di.devnames[0], "ugen", 4) != 0)
+    if (strncmp(di.udi_devnames[0], "ugen", 4) != 0)
       /* best not to play with things we don't understand */
       continue;
 
 #if __FreeBSD__
-    snprintf(buf, sizeof(buf) - 1, "/dev/%s", di.devnames[0]);
+    snprintf(buf, sizeof(buf) - 1, "/dev/%s", di.udi_devnames[0]);
 #else
     snprintf(buf, sizeof(buf) - 1, "/dev/%s.00", di.devnames[0]);
 #endif
