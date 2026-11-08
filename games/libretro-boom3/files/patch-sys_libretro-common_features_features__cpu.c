--- sys/libretro-common/features/features_cpu.c.orig	2022-08-10 06:42:51 UTC
+++ sys/libretro-common/features/features_cpu.c
@@ -181,7 +181,7 @@ retro_perf_tick_t cpu_features_get_perf_counter(void)
    time_ticks = (retro_perf_tick_t)a | ((retro_perf_tick_t)d << 32);
 #elif defined(__ARM_ARCH_6__)
    __asm__ volatile( "mrc p15, 0, %0, c9, c13, 0" : "=r"(time_ticks) );
-#elif defined(__CELLOS_LV2__) || defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__)
+#elif !defined(__FreeBSD__) && (defined(__CELLOS_LV2__) || defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__))
    time_ticks = __mftb();
 #elif defined(GEKKO)
    time_ticks = gettime();
