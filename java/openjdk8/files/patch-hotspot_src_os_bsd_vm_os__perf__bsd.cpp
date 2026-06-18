--- hotspot/src/os/bsd/vm/os_perf_bsd.cpp.orig	2026-01-23 00:36:25 UTC
+++ hotspot/src/os/bsd/vm/os_perf_bsd.cpp
@@ -58,9 +58,9 @@
        */
       #define _MACHINE_PCB_H_
       /*
-       * do not redefine breakpoint on armv7
+       * do not redefine breakpoint on armv7 and aarch64/16
        */
-      #ifdef __arm__
+      #if defined(__arm__) || ( defined (__aarch64__) && __FreeBSD_version >= 160000 )
         #define _MACHINE_CPUFUNC_H_
       #endif
     #endif
