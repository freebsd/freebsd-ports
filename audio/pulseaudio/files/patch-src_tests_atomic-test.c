--- src/tests/atomic-test.c.orig	2019-09-13 13:10:23 UTC
+++ src/tests/atomic-test.c
@@ -51,6 +51,11 @@
 
 #define MEMORY_SIZE (8 * 2 * 1024 * 1024)
 
+#ifdef __FreeBSD__
+#include <sys/cpuset.h>
+#define cpu_set_t cpuset_t
+#endif
+
 
 typedef struct io_t {
    pa_atomic_t *flag;
