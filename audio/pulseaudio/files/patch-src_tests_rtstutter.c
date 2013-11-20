--- src/tests/rtstutter.c.orig	2011-10-20 14:54:17.000000000 +0200
+++ src/tests/rtstutter.c	2011-10-21 12:52:31.000000000 +0200
@@ -30,6 +30,11 @@
 
 #ifdef HAVE_PTHREAD
 #include <pthread.h>
+#ifdef HAVE_PTHREAD_SETAFFINITY_NP 
+#include <pthread_np.h>
+#include <sys/param.h>
+#include <sys/cpuset.h> 
+#endif
 #endif
 
 #include <pulse/util.h>
@@ -54,7 +59,11 @@
 
 #ifdef HAVE_PTHREAD_SETAFFINITY_NP
 {
+#ifdef __FreeBSD__
+    cpuset_t mask;
+#else
     cpu_set_t mask;
+#endif
 
     CPU_ZERO(&mask);
     CPU_SET((size_t) PA_PTR_TO_UINT(p), &mask);
