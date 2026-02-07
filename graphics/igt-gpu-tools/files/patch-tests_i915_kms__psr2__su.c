--- tests/i915/kms_psr2_su.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/kms_psr2_su.c
@@ -29,7 +29,15 @@
 #include <stdbool.h>
 #include <stdio.h>
 #include <string.h>
+#ifdef __linux__
 #include <sys/timerfd.h>
+#endif
+
+/* FreeBSD: POSIX TIMER */
+#ifdef __FreeBSD__
+#define	timerfd_create(c, f)		-1
+#define	timerfd_settime(fd, f, n, o)	-1
+#endif
 
 IGT_TEST_DESCRIPTION("Test PSR2 selective update");
 
