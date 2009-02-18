--- src/dfu.h.orig	2007-02-25 15:43:05.000000000 +0000
+++ src/dfu.h	2009-02-04 22:05:15.000000000 +0000
@@ -21,7 +21,7 @@
 #ifndef __DFU_H__
 #define __DFU_H__
 
-#include <usb.h>
+#include <libusb20_compat01.h>
 #include "usb_dfu.h"
 
 /* DFU states */
