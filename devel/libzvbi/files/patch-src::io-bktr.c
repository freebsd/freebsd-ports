--- src/io-bktr.c.orig	Sat May 17 22:07:06 2003
+++ src/io-bktr.c	Sat May 17 22:08:02 2003
@@ -37,6 +37,7 @@
 #include <unistd.h>
 #include <assert.h>
 #include <sys/time.h>		/* timeval */
+#include <sys/select.h>
 #include <sys/types.h>		/* fd_set */
 #include <sys/ioctl.h>
 #include <sys/mman.h>
