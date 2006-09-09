--- hfkernel/fsk/elbug.c.orig	Sun Jul 30 10:55:08 2006
+++ hfkernel/fsk/elbug.c	Sun Jul 30 12:21:38 2006
@@ -25,7 +25,16 @@
  */
 
 #include <stdio.h>
+#include <sys/types.h>
+#ifdef __linux__
 #include <sys/io.h>
+#define IOPERM ioperm
+#endif
+#ifdef __FreeBSD__ 
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
+#define IOPERM i386_set_ioperm
+#endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
@@ -144,7 +153,7 @@
 	exit (0);
 	}
     }
-    if ((err = ioperm(port, 8, 1))) {
+    if ((err = IOPERM(port, 8, 1))) {
 	printf("permission problem for serial port %04x: ioperm = %d\n", 
 	    port, err);
 	printf("This program has to be called with root permissions.\n");
