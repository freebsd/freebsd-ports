--- bsd.c.orig	Mon Nov 11 19:04:16 2002
+++ bsd.c	Sun Nov 23 15:51:49 2003
@@ -276,7 +276,7 @@
 int usb_bulk_write(usb_dev_handle *dev, int ep, char *bytes, int size,
                    int timeout)
 {
-  int fd, ret, sent = 0;
+  int fd, ret;
 
   /* Ensure the endpoint address is correct */
   ep &= ~USB_ENDPOINT_IN;
@@ -298,8 +298,7 @@
     USB_ERROR_STR(ret, "error setting timeout: %s",
                   strerror(errno));
 
-  do {
-    ret = write(fd, bytes+sent, size-sent);
+    ret = write(fd, bytes, size);
     if (ret < 0)
 #if __FreeBSD__
       USB_ERROR_STR(ret, "error writing to bulk endpoint %s.%d: %s",
@@ -309,16 +308,13 @@
                   dev->device->filename, UE_GET_ADDR(ep), strerror(errno));
 #endif
 
-    sent += ret;
-  } while(ret > 0 && sent < size);
-
-  return sent;
+  return ret;
 }
 
 int usb_bulk_read(usb_dev_handle *dev, int ep, char *bytes, int size,
                   int timeout)
 {
-  int fd, ret, retrieved = 0, one = 1;
+  int fd, ret, one = 1;
 
   /* Ensure the endpoint address is correct */
   ep |= USB_ENDPOINT_IN;
@@ -345,8 +341,7 @@
     USB_ERROR_STR(ret, "error setting short xfer: %s",
                   strerror(errno));
 
-  do {
-    ret = read(fd, bytes+retrieved, size-retrieved);
+    ret = read(fd, bytes, size);
     if (ret < 0)
 #if __FreeBSD__
       USB_ERROR_STR(ret, "error reading from bulk endpoint %s.%d: %s",
@@ -355,10 +350,8 @@
       USB_ERROR_STR(ret, "error reading from bulk endpoint %s.%02d: %s",
                   dev->device->filename, UE_GET_ADDR(ep), strerror(errno));
 #endif
-    retrieved += ret;
-  } while (ret > 0 && retrieved < size);
 
-  return retrieved;
+  return ret;
 }
 
 int usb_control_msg(usb_dev_handle *dev, int requesttype, int request,
