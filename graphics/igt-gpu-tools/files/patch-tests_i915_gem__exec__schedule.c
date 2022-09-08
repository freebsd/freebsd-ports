--- tests/i915/gem_exec_schedule.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_exec_schedule.c
@@ -23,7 +23,9 @@
 
 #include "config.h"
 
+#ifdef __linux__
 #include <linux/userfaultfd.h>
+#endif
 
 #include <pthread.h>
 #include <sys/poll.h>
@@ -64,6 +66,10 @@
 #define   MI_SEMAPHORE_SAD_EQ_SDD       (4 << 12)
 #define   MI_SEMAPHORE_SAD_NEQ_SDD      (5 << 12)
 
+#ifdef __FreeBSD__
+#define	SCHED_RESET_ON_FORK	0
+#endif
+
 IGT_TEST_DESCRIPTION("Check that we can control the order of execution");
 
 static unsigned int offset_in_page(void *addr)
@@ -2510,7 +2516,11 @@ static int userfaultfd(int flags)
 
 static int userfaultfd(int flags)
 {
+#ifdef __linux__
 	return syscall(SYS_userfaultfd, flags);
+#elif defined(__FreeBSD__)
+	return -ENOSYS;
+#endif
 }
 
 struct ufd_thread {
@@ -2569,6 +2579,7 @@ static void test_pi_userfault(int i915,
 			      const intel_ctx_cfg_t *cfg,
 			      unsigned int engine)
 {
+#ifdef __linux__
 	const uint32_t bbe = MI_BATCH_BUFFER_END;
 	struct uffdio_api api = { .api = UFFD_API };
 	struct uffdio_register reg;
@@ -2670,6 +2681,7 @@ static void test_pi_userfault(int i915,
 	gem_close(i915, t.batch);
 	munmap(t.page, 4096);
 	close(ufd);
+#endif
 }
 
 static void *iova_thread(struct ufd_thread *t, int prio)
@@ -2705,6 +2717,7 @@ static void test_pi_iova(int i915, const intel_ctx_cfg
 static void test_pi_iova(int i915, const intel_ctx_cfg_t *cfg,
 			 unsigned int engine, unsigned int flags)
 {
+#ifdef __linux__
 	intel_ctx_cfg_t ufd_cfg = *cfg;
 	const intel_ctx_t *spinctx;
 	struct uffdio_api api = { .api = UFFD_API };
@@ -2839,6 +2852,7 @@ static void test_pi_iova(int i915, const intel_ctx_cfg
 		gem_vm_destroy(i915, ufd_cfg.vm);
 
 	close(ufd);
+#endif
 }
 
 static void measure_semaphore_power(int i915, const intel_ctx_t *ctx)
