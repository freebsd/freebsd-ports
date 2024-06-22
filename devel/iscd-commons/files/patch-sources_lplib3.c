--- sources/lplib3.c.orig	2021-07-23 10:27:28 UTC
+++ sources/lplib3.c
@@ -30,6 +30,9 @@
 #include <assert.h>
 #include <errno.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <pmc.h>
+#endif
 #include "lplib3.h"
 
 
@@ -1251,6 +1254,7 @@ void qsort_mt(void *a, size_t n, size_t es, cmp_t *cmp
 		 * NPROC environment variable (BSD/OS, CrayOS)
 		 * sysctl hw.ncpu or kern.smp.cpus
 		 */
+		uint32_t ncpu;
 		if (pmc_init() == 0 && (ncpu = pmc_ncpu()) != -1)
 			maxthreads = ncpu;
 		else
