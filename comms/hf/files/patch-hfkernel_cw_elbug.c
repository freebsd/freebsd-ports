--- hfkernel/cw/elbug.c.orig	Sun Apr 15 15:53:59 2007
+++ hfkernel/cw/elbug.c	Sun Apr 15 15:56:17 2007
@@ -36,7 +36,10 @@
 #ifdef __FreeBSD__ 
 #include <machine/cpufunc.h>
 #include <machine/sysarch.h>
+#include <sys/kbio.h>
 #define IOPERM i386_set_ioperm
+#else
+#include <sys/kd.h>		/* Linux, UnixWare */
 #endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
@@ -44,7 +47,6 @@
 #include <unistd.h>
 #include <string.h>
 #include <stdlib.h>
-#include <sys/kd.h>		/* Linux, UnixWare */
 /*
 if kd.h not found, maybe you have to take one of these 2:
 <sys/vtkd.h> for OpenServer
