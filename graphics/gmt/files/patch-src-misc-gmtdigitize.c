--- src/misc/gmtdigitize.c.orig	2016-03-07 01:35:42 UTC
+++ src/misc/gmtdigitize.c
@@ -38,11 +38,7 @@
  */
 
 /* Circumvent Solaris problem. See bug #817 */
-#ifdef __FreeBSD__
-#define _XOPEN_SOURCE
-#else
 #define _XOPEN_SOURCE 600
-#endif
  
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
