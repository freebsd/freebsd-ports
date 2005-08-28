--- writev.c.orig	Sat Aug  6 16:16:18 2005
+++ writev.c	Sat Aug  6 16:17:00 2005
@@ -32,12 +32,17 @@
 #pragma ident	"@(#)writev.c	1.7	05/08/04 SMI"
 #endif
 
+#include <sys/types.h>
 #include <sys/uio.h>
 #include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <fcntl.h>
+
+#ifndef UIO_MAXIOV
+#define UIO_MAXIOV 1024
+#endif
 
 #ifndef IOV_MAX
 #define	IOV_MAX			UIO_MAXIOV
