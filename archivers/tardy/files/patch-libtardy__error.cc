--- ./libtardy/error.cc.orig	2010-03-10 03:50:43.000000000 +0100
+++ ./libtardy/error.cc	2010-05-21 15:20:47.000000000 +0200
@@ -33,6 +33,10 @@
 #include <libtardy/mprintf.h>
 #include <libtardy/progname.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 
 static void
 error_get_id(int *uid, int *gid)
