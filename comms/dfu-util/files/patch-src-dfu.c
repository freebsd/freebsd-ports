--- src/dfu.c.orig	2007-02-25 15:43:05.000000000 +0000
+++ src/dfu.c	2009-02-04 22:05:08.000000000 +0000
@@ -19,7 +19,7 @@
  */
 
 #include <stdio.h>
-#include <usb.h>
+#include <libusb20_compat01.h>
 #include "dfu.h"
 
 /* DFU commands */
