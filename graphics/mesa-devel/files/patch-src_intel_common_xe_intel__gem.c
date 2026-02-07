--- src/intel/common/xe/intel_gem.c.orig	2024-06-05 23:45:33 UTC
+++ src/intel/common/xe/intel_gem.c
@@ -69,7 +69,9 @@ xe_gem_read_correlate_cpu_gpu_timestamp(int fd,
 #endif
    case CLOCK_REALTIME:
 #ifdef CLOCK_BOOTTIME
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
    case CLOCK_BOOTTIME:
+#endif
 #endif
 #ifdef CLOCK_TAI
    case CLOCK_TAI:
