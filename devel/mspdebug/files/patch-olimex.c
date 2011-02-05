--- olimex.c.orig	2010-11-09 08:40:57.000000000 +1100
+++ olimex.c	2011-01-23 20:52:02.005008013 +1100
@@ -20,6 +20,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <usb.h>
+#include <stdlib.h>
 
 #include "olimex.h"
 #include "util.h"
@@ -66,7 +67,7 @@
 static int open_interface(struct olimex_transport *tr,
 			  struct usb_device *dev, int ino)
 {
-#if !(defined (__APPLE__) || defined(WIN32))
+#if defined(__linux__)
 	int drv;
 	char drName[256];
 #endif
@@ -82,7 +83,7 @@
 		return -1;
 	}
 
-#if !(defined(__APPLE__) || defined(WIN32))
+#if defined(__linux__)
 	drv = usb_get_driver_np(tr->handle, tr->int_number, drName,
 				sizeof(drName));
 	printc(__FILE__" : driver %d\n", drv);
