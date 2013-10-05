--- libs/std/sys.c.orig	2013-10-03 01:47:05.000000000 +0900
+++ libs/std/sys.c	2013-10-03 01:45:35.000000000 +0900
@@ -41,7 +41,11 @@
 #	include <sys/time.h>
 #	include <sys/times.h>
 #	include <sys/wait.h>
+#   if __FreeBSD_version >= 900044
 #	include <xlocale.h>
+#   else
+#       undef NEKO_POSIX
+#   endif
 #endif
 
 #ifdef NEKO_MAC
