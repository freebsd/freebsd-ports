--- src/panfrost/perf/pan_perf.h.orig	2026-08-05 21:14:26 UTC
+++ src/panfrost/perf/pan_perf.h
@@ -48,7 +48,10 @@ pan_perf_gpu_clock_id(const struct pan_perf *perf)
 static inline clockid_t
 pan_perf_gpu_clock_id(const struct pan_perf *perf)
 {
+#if defined(CLOCK_MONOTONIC_RAW)
    return CLOCK_MONOTONIC_RAW;
+#endif
+   return CLOCK_MONOTONIC_FAST;
 }
 
 static inline uint64_t
