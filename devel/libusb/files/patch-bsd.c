--- bsd.c.orig	Thu Feb  7 06:43:25 2002
+++ bsd.c	Mon Mar 11 13:39:50 2002
@@ -34,6 +34,7 @@
 #include <assert.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
 
 #include <dev/usb/usb.h>
 
@@ -151,8 +152,13 @@
   if (dev->interface < 0)
     USB_ERROR(-EINVAL);
 
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
   intf.interface_index = dev->interface;
   intf.alt_no = alternate;
+#else
+  intf.uai_interface_index = dev->interface;
+  intf.uai_alt_no = alternate;
+#endif
 
   ret = ioctl(dev->fd, USB_SET_ALTINTERFACE, &intf);
   if (ret < 0)
@@ -284,6 +290,7 @@
     fprintf(stderr, "usb_control_msg: %d %d %d %d %p %d %d\n",
             requesttype, request, value, index, bytes, size, timeout);
 
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
   req.request.bmRequestType = requesttype;
   req.request.bRequest = request;
   USETW(req.request.wValue, value);
@@ -292,6 +299,16 @@
 
   req.data = bytes;
   req.flags = 0;
+#else
+  req.ucr_request.bmRequestType = requesttype;
+  req.ucr_request.bRequest = request;
+  USETW(req.ucr_request.wValue, value);
+  USETW(req.ucr_request.wIndex, index);
+  USETW(req.ucr_request.wLength, size);
+
+  req.ucr_data = bytes;
+  req.ucr_flags = 0;
+#endif
 
   ret = ioctl(dev->fd, USB_SET_TIMEOUT, &timeout);
   if (ret < 0)
@@ -303,7 +320,11 @@
     USB_ERROR_STR(ret, "error sending control message: %s",
                   strerror(errno));
 
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
   return UGETW(req.request.wLength);
+#else
+  return UGETW(req.ucr_request.wLength);
+#endif
 }
 
 int usb_find_devices_on_bus(struct usb_bus *bus)
@@ -321,18 +342,30 @@
     struct usb_device *dev;
     char buf[20];
 
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
     di.addr = device;
+#else
+    di.udi_addr = device;
+#endif
     if (ioctl(cfd, USB_DEVICEINFO, &di) < 0)
       continue;
 
     /* There's a device; is it one we should mess with? */
 
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
     if (strncmp(di.devnames[0], "ugen", 4) != 0)
+#else
+    if (strncmp(di.udi_devnames[0], "ugen", 4) != 0)
+#endif
       /* best not to play with things we don't understand */
       continue;
 
 #if __FreeBSD__
+#if (__FreeBSD_version > 500000 && __FreeBSD_version < 500031) || (__FreeBSD_version < 450001)
     snprintf(buf, sizeof(buf) - 1, "/dev/%s", di.devnames[0]);
+#else
+    snprintf(buf, sizeof(buf) - 1, "/dev/%s", di.udi_devnames[0]);
+#endif
 #else
     snprintf(buf, sizeof(buf) - 1, "/dev/%s.00", di.devnames[0]);
 #endif
