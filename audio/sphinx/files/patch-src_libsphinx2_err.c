--- src/libsphinx2/err.c.orig	2001-12-13 21:11:20 UTC
+++ src/libsphinx2/err.c
@@ -49,6 +49,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #if ((! WIN32) && (! _SGI_SOURCE))
 #include <sys/errno.h>
 #else
