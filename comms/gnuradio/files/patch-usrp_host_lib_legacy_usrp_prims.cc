--- usrp/host/lib/legacy/usrp_prims.cc.orig	2009-01-13 08:53:35.000000000 -0600
+++ usrp/host/lib/legacy/usrp_prims.cc	2009-01-13 19:19:08.000000000 -0600
@@ -129,16 +129,14 @@
 // able to get from a usb_dev_handle back to a usb_device, and the
 // right way to do this is buried in a non-installed include file.
 
+// Modified 13 Jan 09 for libusb20
+
+
 static struct usb_device *
 dev_handle_to_dev (usb_dev_handle *udh)
 {
-  struct usb_dev_handle_kludge {
-    int			 fd;
-    struct usb_bus	*bus;
-    struct usb_device	*device;
-  };
-
-  return ((struct usb_dev_handle_kludge *) udh)->device;
+  return (usb_device(udh));
+//xxx
 }
 
 // ----------------------------------------------------------------
