--- libretro-common/features/features_cpu.c.orig	2024-07-29 22:13:03 UTC
+++ libretro-common/features/features_cpu.c
@@ -45,7 +45,7 @@
 
 #if defined(_XBOX360)
 #include <PPCIntrinsics.h>
-#elif !defined(__MACH__) && (defined(__POWERPC__) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC64__) || defined(__powerpc64__))
+#elif !defined(__MACH__) && !defined(__FreeBSD__) && (defined(__POWERPC__) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC64__) || defined(__powerpc64__))
 #ifndef _PPU_INTRINSICS_H
 #include <ppu_intrinsics.h>
 #endif
@@ -181,7 +181,7 @@ retro_perf_tick_t cpu_features_get_perf_counter(void)
    time_ticks = (1000000 * tv_sec + tv_usec);
 #elif defined(GEKKO)
    time_ticks = gettime();
-#elif !defined(__MACH__) && (defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__) || defined(__PSL1GHT__) || defined(__PPC64__) || defined(__powerpc64__))
+#elif !defined(__MACH__) && !defined(__FreeBSD__) && (defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__) || defined(__PSL1GHT__) || defined(__PPC64__) || defined(__powerpc64__))
    time_ticks = __mftb();
 #elif (defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK > 0) || defined(__QNX__) || defined(ANDROID)
    struct timespec tv;
