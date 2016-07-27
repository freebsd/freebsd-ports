--- writev.c.orig	2011-05-11 00:58:23 UTC
+++ writev.c
@@ -28,6 +28,7 @@
  * Use is subject to license terms.
  */
 
+#include <sys/types.h>
 #include <sys/uio.h>
 #include <limits.h>
 #include <unistd.h>
@@ -35,6 +36,10 @@
 #include <stdio.h>
 #include <fcntl.h>
 
+#ifndef UIO_MAXIOV
+#define UIO_MAXIOV 1024
+#endif
+
 #ifndef IOV_MAX
 #define	IOV_MAX			UIO_MAXIOV
 #endif
