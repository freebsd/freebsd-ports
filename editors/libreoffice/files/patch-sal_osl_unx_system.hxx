--- sal/osl/unx/system.hxx.orig	2015-08-22 06:41:35 UTC
+++ sal/osl/unx/system.hxx
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
