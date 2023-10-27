--- desmume/src/libretro-common/features/features_cpu.c.orig	2022-04-05 21:03:52 UTC
+++ desmume/src/libretro-common/features/features_cpu.c
@@ -138,7 +138,7 @@ retro_perf_tick_t cpu_features_get_perf_counter(void)
    tv_sec     = (long)((ularge.QuadPart - epoch) / 10000000L);
    tv_usec    = (long)(system_time.wMilliseconds * 1000);
    time_ticks = (1000000 * tv_sec + tv_usec);
-#elif defined(__linux__) || defined(__QNX__) || defined(__MACH__)
+#elif defined(_POSIX_MONOTONIC_CLOCK) || defined(__QNX__) || defined(ANDROID) || defined(__MACH__) || defined(__PSL1GHT__)
    struct timespec tv = {0};
    if (ra_clock_gettime(CLOCK_MONOTONIC, &tv) == 0)
       time_ticks = (retro_perf_tick_t)tv.tv_sec * 1000000000 +
