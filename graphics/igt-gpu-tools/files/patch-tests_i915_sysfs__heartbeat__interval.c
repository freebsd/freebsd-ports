--- tests/i915/sysfs_heartbeat_interval.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/sysfs_heartbeat_interval.c
@@ -42,6 +42,10 @@
 #include "igt_sysfs.h"
 #include "sw_sync.h"
 
+#ifdef __FreeBSD__
+#define	sighandler_t	sig_t
+#endif
+
 #define ATTR "heartbeat_interval_ms"
 #define RESET_TIMEOUT 50 /* milliseconds, at least one jiffie for kworker */
 
