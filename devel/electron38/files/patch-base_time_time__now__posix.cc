--- base/time/time_now_posix.cc.orig	2025-08-26 20:49:50 UTC
+++ base/time/time_now_posix.cc
@@ -110,7 +110,11 @@ TimeTicks TimeTicksLowResolutionNowIgnoringOverride() 
 }
 
 TimeTicks TimeTicksLowResolutionNowIgnoringOverride() {
+#if BUILDFLAG(IS_BSD)
+  return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC));
+#else
   return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC_COARSE));
+#endif
 }
 }  // namespace subtle
 
