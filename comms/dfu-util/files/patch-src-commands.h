--- src/commands.h.orig	2007-02-22 21:33:15.000000000 +0000
+++ src/commands.h	2009-02-04 22:04:41.000000000 +0000
@@ -21,7 +21,7 @@
 #ifndef __COMMANDS_H__
 #define __COMMANDS_H__
 
-#include <usb.h>
+#include <libusb20_compat01.h>
 #include "arguments.h"
 
 int execute_command( struct usb_dev_handle *device,
