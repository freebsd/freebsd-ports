--- src/linux/rw_in_aa.c.orig	Thu Jun 12 18:31:47 2003
+++ src/linux/rw_in_aa.c	Thu Jun 12 18:32:19 2003
@@ -40,13 +40,14 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/vt.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
 #include <sys/mman.h>
-
+#ifdef __linux__
+#include <sys/vt.h>
 #include <asm/io.h>
+#endif
 
 #include <aalib.h>
 
