--- include/swoole.h.orig	2017-01-24 02:05:48 UTC
+++ include/swoole.h
@@ -40,7 +40,17 @@ extern "C" {
 #include <assert.h>
 #include <time.h>
 #include <pthread.h>
+
+#if defined(HAVE_CPU_AFFINITY)
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/cpuset.h>
+#include <pthread_np.h>
+typedef cpuset_t cpu_set_t;
+#else
 #include <sched.h>
+#endif
+#endif
 
 #include <arpa/inet.h>
 #include <netinet/in.h>
