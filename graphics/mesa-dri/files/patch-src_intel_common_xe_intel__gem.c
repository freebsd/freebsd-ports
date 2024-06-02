--- src/intel/common/xe/intel_gem.c.orig	2024-05-22 09:48:39.000000000 -0700
+++ src/intel/common/xe/intel_gem.c	2024-06-01 06:28:22.268439000 -0700
@@ -69,8 +69,10 @@
 #endif
    case CLOCK_REALTIME:
 #ifdef CLOCK_BOOTTIME
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
    case CLOCK_BOOTTIME:
 #endif
+#endif
 #ifdef CLOCK_TAI
    case CLOCK_TAI:
 #endif
