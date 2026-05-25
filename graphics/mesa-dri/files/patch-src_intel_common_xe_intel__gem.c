--- src/intel/common/xe/intel_gem.c.orig	2026-04-15 14:20:41 UTC
+++ src/intel/common/xe/intel_gem.c
@@ -72,7 +72,9 @@ xe_gem_read_correlate_cpu_gpu_timestamp(int fd,
 #endif
    case CLOCK_REALTIME:
 #ifdef CLOCK_BOOTTIME
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
    case CLOCK_BOOTTIME:
+#endif
 #endif
 #ifdef CLOCK_TAI
    case CLOCK_TAI:
