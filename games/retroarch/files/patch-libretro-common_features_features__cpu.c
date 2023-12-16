--- libretro-common/features/features_cpu.c.orig	2023-12-12 02:50:19.541552000 +0000
+++ libretro-common/features/features_cpu.c	2023-12-12 02:52:13.056521000 +0000
@@ -45,7 +45,7 @@
 
 #if defined(_XBOX360)
 #include <PPCIntrinsics.h>
-#elif !defined(__MACH__) && (defined(__POWERPC__) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC64__) || defined(__powerpc64__))
+#elif !defined(__MACH__) && !defined(__FreeBSD__) && (defined(__POWERPC__) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC64__) || defined(__powerpc64__))
 #ifndef _PPU_INTRINSICS_H
 #include <ppu_intrinsics.h>
 #endif
@@ -181,7 +181,7 @@
    time_ticks = (1000000 * tv_sec + tv_usec);
 #elif defined(GEKKO)
    time_ticks = gettime();
-#elif !defined(__MACH__) && (defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__) || defined(__PSL1GHT__) || defined(__PPC64__) || defined(__powerpc64__))
+#elif !defined(__MACH__) && !defined(__FreeBSD__) && (defined(_XBOX360) || defined(__powerpc__) || defined(__ppc__) || defined(__POWERPC__) || defined(__PSL1GHT__) || defined(__PPC64__) || defined(__powerpc64__))
    time_ticks = __mftb();
 #elif (defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK > 0) || defined(__QNX__) || defined(ANDROID)
    struct timespec tv;
