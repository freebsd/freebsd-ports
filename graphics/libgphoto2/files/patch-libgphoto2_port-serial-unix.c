--- libgphoto2_port/serial/unix.c.orig	Fri Jul 27 02:36:13 2007
+++ libgphoto2_port/serial/unix.c	Mon Aug 13 17:26:43 2007
@@ -43,6 +43,7 @@
 #endif
 #include <string.h>
 #include <signal.h>
+#include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #ifdef HAVE_SYS_TIME_H
