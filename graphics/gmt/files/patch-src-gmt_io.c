--- src/gmt_io.c.orig	2016-03-07 01:35:42 UTC
+++ src/gmt_io.c
@@ -80,11 +80,7 @@
  */
 
 /* Circumvent Solaris problem. See bug #817 */
-#ifdef __FreeBSD__
-#define _XOPEN_SOURCE
-#else
 #define _XOPEN_SOURCE 600
-#endif
 
 #define GMT_WITH_NO_PS
 #include "gmt.h"
