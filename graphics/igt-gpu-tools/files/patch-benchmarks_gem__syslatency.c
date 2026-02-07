--- benchmarks/gem_syslatency.c.orig	2022-08-31 20:00:00 UTC
+++ benchmarks/gem_syslatency.c
@@ -42,12 +42,21 @@
 #include <limits.h>
 #include "drm.h"
 
+#ifdef __linux__
 #include <linux/unistd.h>
+#elif defined(__FreeBSD__)
+#include <sys/mman.h>
+#define	MAP_POPULATE	MAP_PREFAULT_READ
+#define	gettid()	getpid()
+#define	MADV_HUGEPAGE	MADV_SEQUENTIAL
+#endif
 
 #include "i915/gem_create.h"
 #include "i915/gem_ring.h"
 
+#ifdef __linux__
 #define sigev_notify_thread_id _sigev_un._tid
+#endif
 
 static volatile int done;
 
