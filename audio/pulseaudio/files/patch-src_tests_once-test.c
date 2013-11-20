--- src/tests/once-test.c.orig	2011-10-20 14:54:17.000000000 +0200
+++ src/tests/once-test.c	2011-10-21 12:52:15.000000000 +0200
@@ -23,6 +23,11 @@
 
 #ifdef HAVE_PTHREAD
 #include <pthread.h>
+#ifdef HAVE_PTHREAD_SETAFFINITY_NP 
+#include <pthread_np.h>
+#include <sys/param.h>
+#include <sys/cpuset.h> 
+#endif
 #endif
 
 #include <pulsecore/thread.h>
@@ -54,7 +59,11 @@
 
 #ifdef HAVE_PTHREAD_SETAFFINITY_NP
     static pa_atomic_t i_cpu = PA_ATOMIC_INIT(0);
+#ifdef __FreeBSD__
+    cpuset_t mask;
+#else
     cpu_set_t mask;
+#endif
 
     CPU_ZERO(&mask);
     CPU_SET((size_t) (pa_atomic_inc(&i_cpu) % n_cpu), &mask);
