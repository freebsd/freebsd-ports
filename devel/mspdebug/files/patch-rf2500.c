--- rf2500.c.orig	2010-11-09 08:40:57.000000000 +1100
+++ rf2500.c	2011-01-23 20:51:40.771589070 +1100
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <usb.h>
+#include <stdlib.h>
 
 #include "rf2500.h"
 #include "util.h"
@@ -67,7 +68,7 @@
 		return -1;
 	}
 
-#if !(defined(__APPLE__) || defined(WIN32))
+#if !(defined(__APPLE__) || defined(WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__))
 	if (usb_detach_kernel_driver_np(tr->handle, tr->int_number) < 0)
 		pr_error("rf2500: warning: can't "
 			"detach kernel driver");
@@ -221,7 +222,7 @@
 #ifndef __APPLE__
 	while (usb_bulk_read(tr->handle, USB_FET_IN_EP,
 			     buf, sizeof(buf),
-			     100) >= 0);
+			     100) > 0);
 #endif
 
 	return (transport_t)tr;
