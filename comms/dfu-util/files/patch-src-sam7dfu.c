--- src/sam7dfu.c	2009-02-09 01:50:55.118776000 +0000
+++ src/sam7dfu.c	2009-02-12 21:15:27.000000000 +0000
@@ -12,7 +12,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <string.h>
-#include <usb.h>
+#include <libusb20_compat01.h>
 
 #include "config.h"
 #include "dfu.h"
