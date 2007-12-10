--- src/libsphinx2/err.c.orig	2007-12-06 18:22:49.000000000 +0100
+++ src/libsphinx2/err.c	2007-12-06 18:23:27.000000000 +0100
@@ -49,6 +49,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #if ((! WIN32) && (! _SGI_SOURCE))
 #include <sys/errno.h>
 #else
