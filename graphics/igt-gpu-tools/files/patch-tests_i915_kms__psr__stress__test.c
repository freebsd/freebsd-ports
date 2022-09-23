--- tests/i915/kms_psr_stress_test.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/kms_psr_stress_test.c
@@ -6,7 +6,9 @@
 #include <stdbool.h>
 #include <stdio.h>
 #include <string.h>
+#ifdef __linux__
 #include <sys/timerfd.h>
+#endif
 
 #define INVALIDATES_PER_SEC 15
 #define FLIPS_PER_SEC 30
@@ -18,6 +20,12 @@
 #define FRAMEBUFFERS_LEN 60
 
 #define DRAW_METHOD IGT_DRAW_BLT
+
+/* FreeBSD: POSIX TIMER */
+#ifdef __FreeBSD__
+#define	timerfd_create(c, f)		-1
+#define	timerfd_settime(fd, f, n, o)	-1
+#endif
 
 typedef struct {
 	int drm_fd;
@@ -374,4 +382,4 @@ igt_main
 		close(data.debugfs_fd);
 		close(data.drm_fd);
 	}
-}
\ No newline at end of file
+}
