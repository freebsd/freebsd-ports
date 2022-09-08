--- lib/igt_dummyload.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_dummyload.c
@@ -26,7 +26,9 @@
 #include <signal.h>
 #include <pthread.h>
 #include <sys/poll.h>
+#ifdef __linux__
 #include <sys/timerfd.h>
+#endif
 
 #include <i915_drm.h>
 
@@ -523,6 +525,8 @@ void igt_spin_set_timeout(igt_spin_t *spin, int64_t ns
  */
 void igt_spin_set_timeout(igt_spin_t *spin, int64_t ns)
 {
+/* TODO: FreeBSD - POSIX TIMER */
+#ifdef __linux__
 	struct sched_param param = { .sched_priority = 99 };
 	struct itimerspec its;
 	pthread_attr_t attr;
@@ -554,6 +558,7 @@ void igt_spin_set_timeout(igt_spin_t *spin, int64_t ns
 	its.it_value.tv_sec = ns / NSEC_PER_SEC;
 	its.it_value.tv_nsec = ns % NSEC_PER_SEC;
 	igt_assert(timerfd_settime(timerfd, 0, &its, NULL) == 0);
+#endif
 }
 
 static void sync_write(igt_spin_t *spin, uint32_t value)
