--- src/burner/libretro/libretro-common/features/features_cpu.c.orig	2020-08-25 12:19:30 UTC
+++ src/burner/libretro/libretro-common/features/features_cpu.c
@@ -167,7 +167,7 @@ retro_perf_tick_t cpu_features_get_perf_counter(void)
    tv_sec     = (long)((ularge.QuadPart - epoch) / 10000000L);
    tv_usec    = (long)(system_time.wMilliseconds * 1000);
    time_ticks = (1000000 * tv_sec + tv_usec);
-#elif defined(__linux__) || defined(__QNX__) || defined(__MACH__)
+#elif defined(_POSIX_MONOTONIC_CLOCK) || defined(__QNX__) || defined(ANDROID) || defined(__MACH__) || defined(__PSL1GHT__)
    struct timespec tv = {0};
    if (ra_clock_gettime(CLOCK_MONOTONIC, &tv) == 0)
       time_ticks = (retro_perf_tick_t)tv.tv_sec * 1000000000 +
@@ -181,7 +181,7 @@ retro_perf_tick_t cpu_features_get_perf_counter(void)
    time_ticks = (retro_perf_tick_t)a | ((retro_perf_tick_t)d << 32);
 #elif defined(__ARM_ARCH_6__)
    __asm__ volatile( "mrc p15, 0, %0, c9, c13, 0" : "=r"(time_ticks) );
-#elif defined(__CELLOS_LV2__) || defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__)
+#elif defined(__CELLOS_LV2__) || defined(_XBOX360)
    time_ticks = __mftb();
 #elif defined(GEKKO)
    time_ticks = gettime();
