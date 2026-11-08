Description: Count CPUs with sysconf(_SC_NPROCESSORS_ONLN) instead of libpmc;
  libCommons.so is not linked with libpmc, so loading it failed.
Issue ID: https://github.com/ISCDtoolbox/Commons/pull/4
Changeset: none
TODO: Submit upstream; drop once a release includes the fix.

--- sources/lplib3.c.orig	2021-07-23 10:27:28 UTC
+++ sources/lplib3.c
@@ -1251,7 +1251,8 @@ void qsort_mt(void *a, size_t n, size_t es, cmp_t *cmp
 		 * NPROC environment variable (BSD/OS, CrayOS)
 		 * sysctl hw.ncpu or kern.smp.cpus
 		 */
-		if (pmc_init() == 0 && (ncpu = pmc_ncpu()) != -1)
+		long ncpu;
+		if ((ncpu = sysconf(_SC_NPROCESSORS_ONLN)) > 0)
 			maxthreads = ncpu;
 		else
 			maxthreads = 2;
