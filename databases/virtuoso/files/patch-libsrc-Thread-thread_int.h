--- libsrc/Thread/thread_int.h.orig	Mon Jan 22 06:28:12 2007
+++ libsrc/Thread/thread_int.h	Sun Nov 25 10:31:20 2007
@@ -36,2 +36,3 @@
 #include <assert.h>
+#include <pthread.h>		/* For FreeBSD 5.x */
 #define _THREAD_INT_HS
