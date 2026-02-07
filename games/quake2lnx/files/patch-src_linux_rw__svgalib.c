--- src/linux/rw_svgalib.c.orig	Thu Jun 12 18:41:01 2003
+++ src/linux/rw_svgalib.c	Thu Jun 12 18:41:41 2003
@@ -36,7 +36,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
