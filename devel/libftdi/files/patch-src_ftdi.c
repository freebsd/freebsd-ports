--- src/ftdi.c.orig	2009-05-04 23:37:26.000000000 +0400
+++ src/ftdi.c	2009-05-04 23:37:46.000000000 +0400
@@ -28,6 +28,7 @@
 /** \addtogroup libftdi */
 /* @{ */
 
+#include <stdlib.h>
 #include <usb.h>
 #include <string.h>
 #include <errno.h>
