--- hfkernel/fsk/cw.c.orig	Sun Jul 30 10:49:09 2006
+++ hfkernel/fsk/cw.c	Sun Jul 30 11:57:13 2006
@@ -35,7 +35,16 @@
 #include <syslog.h>
 #include <string.h>
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
 #include <time.h>
 #include <sys/ioctl.h>
@@ -264,7 +273,7 @@
 		"CW: No serial port specified for elbug.");
 	    printf("CW: No serial port specified for elbug.\n");
 	}
-	else if ((err = ioperm(port, 8, 1))) {
+	else if ((err = IOPERM(port, 8, 1))) {
 	    printf("CW: permission problem for serial port %04x: ioperm = %d\n", 
 		port, err);
 	    printf("This program has to be called with root permissions.\n");
