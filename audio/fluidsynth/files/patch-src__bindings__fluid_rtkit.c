--- src/bindings/fluid_rtkit.c.orig	2011-09-04 16:38:58.000000000 +0900
+++ src/bindings/fluid_rtkit.c	2011-09-05 17:07:06.000000000 +0900
@@ -34,7 +34,7 @@
 #include "fluid_rtkit.h"
 
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
@@ -44,12 +44,27 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/syscall.h>
 #include <sys/resource.h>
+#include <sys/param.h>
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 
 static pid_t _gettid(void) {
+#if defined(__FreeBSD__)
+#if __FreeBSD__version > 900030
+        return pthread_getthreadid_np();
+#else
+        long tid;
+        syscall(SYS_thr_self, &tid);
+        return tid;	
+#endif
+#else
         return (pid_t) syscall(SYS_gettid);
+#endif
 }
 
 static int translate_error(const char *name) {
