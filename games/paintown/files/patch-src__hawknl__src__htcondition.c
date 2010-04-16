--- src/hawknl/src/htcondition.c.orig	2010-04-14 20:48:09.000000000 +0200
+++ src/hawknl/src/htcondition.c	2010-04-14 20:48:09.000000000 +0200
@@ -37,6 +37,9 @@
 
 #else /* !HT_WIN_THREADS */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <sys/timeb.h>
 
 #ifdef HL_WINDOWS_APP
