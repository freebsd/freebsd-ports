--- src/main.c	2009-02-09 01:50:55.118776000 +0000
+++ src/main.c	2009-02-12 21:15:13.000000000 +0000
@@ -26,7 +26,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <getopt.h>
-#include <usb.h>
+#include <libusb20_compat01.h>
 #include <errno.h>
 
 #include "dfu.h"
