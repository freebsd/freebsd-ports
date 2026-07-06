--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2026-06-19 18:57:03 UTC
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -44,9 +44,9 @@
        */
       #define _MACHINE_PCB_H_
       /*
-       * do not redefine breakpoint on armv7
+       * do not redefine breakpoint
        */
-      #ifdef __arm__
+      #if defined(__arm__) || ( defined (__aarch64__) && __FreeBSD_version >= 160000 )
         #define _MACHINE_CPUFUNC_H_
       #endif
     #endif
