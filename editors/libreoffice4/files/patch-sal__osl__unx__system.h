--- sal/osl/unx/system.h.orig	2014-09-16 16:10:41.000000000 -0400
+++ sal/osl/unx/system.h	2014-10-14 14:31:50.000000000 -0400
@@ -113,7 +113,9 @@
 #endif
 
 #ifdef FREEBSD
-#   define  ETIME ETIMEDOUT
+#   ifndef ETIME
+#       define ETIME ETIMEDOUT
+#   endif
 #   include <pthread.h>
 #   include <sys/sem.h>
 #   include <dlfcn.h>
