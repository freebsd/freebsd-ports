--- encodedv/dvconnect.c.orig	Sun Jun 24 13:21:45 2001
+++ encodedv/dvconnect.c	Mon Nov 19 00:53:05 2001
@@ -24,6 +24,7 @@
  */
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <string.h>
@@ -38,7 +39,7 @@
 #include <popt.h>
 #endif
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #define CIP_N_NTSC 2436
 #define CIP_D_NTSC 38400
