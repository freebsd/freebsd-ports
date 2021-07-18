--- libs/indicom.c	2021-04-22 12:28:35.000000000 -0500
+++ libs/indicom.c	2021-05-11 12:29:20.391397000 -0500
@@ -32,6 +32,7 @@
 #include "base64.h"
 
 #include "config.h"
+#include <sys/param.h>
 
 #if defined(HAVE_LIBNOVA)
 #include <libnova/julian_day.h>
@@ -61,7 +62,9 @@
 #endif
 
 #if defined(BSD) && !defined(__GNU__)
+#if defined __APPLE__
 #include <IOKit/serial/ioss.h>
+#endif
 #include <sys/ioctl.h>
 #endif
 
@@ -763,7 +766,7 @@
     case 57600:  bps = B57600;  break;
     case 115200: bps = B115200; break;
     case 230400: bps = B230400; break;
-#ifndef __APPLE__
+#if !defined(__FreeBSD__)
     case 460800: bps = B460800; break;
     case 576000: bps = B576000; break;
     case 921600: bps = B921600; break;
