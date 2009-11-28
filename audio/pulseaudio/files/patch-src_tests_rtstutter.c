--- src/tests/rtstutter.c.orig	2009-07-23 15:40:47.000000000 +0200
+++ src/tests/rtstutter.c	2009-11-24 16:26:36.000000000 +0100
@@ -31,6 +31,11 @@
 #include <string.h>
 #include <pthread.h>
 
+#ifdef HAVE_PTHREAD_SETAFFINITY_NP 
+#include <sys/param.h>
+#include <sys/cpuset.h> 
+#endif
+
 #include <pulse/timeval.h>
 #include <pulse/gccmacro.h>
 
@@ -44,8 +49,12 @@
 
 static void* work(void *p) {
 #ifdef HAVE_PTHREAD_SETAFFINITY_NP
+#ifdef __FreeBSD__
+    cpuset_t mask;
+#else
     cpu_set_t mask;
 #endif
+#endif
     struct sched_param param;
 
     pa_log_notice("CPU%i: Created thread.", PA_PTR_TO_UINT(p));
