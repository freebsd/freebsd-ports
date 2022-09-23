--- tests/i915/gem_exec_latency.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_exec_latency.c
@@ -55,6 +55,10 @@
 #define CORK 0x2
 #define PREEMPT 0x4
 
+#ifdef __FreeBSD__
+#define	SCHED_RESET_ON_FORK	0
+#endif
+
 static unsigned int ring_size;
 static double rcs_clock;
 static struct intel_mmio_data mmio_data;
