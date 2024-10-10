--- hotspot/src/os/bsd/vm/os_perf_bsd.cpp.orig	2024-10-10 08:36:27 UTC
+++ hotspot/src/os/bsd/vm/os_perf_bsd.cpp
@@ -57,6 +57,12 @@
        * with the same name.
        */
       #define _MACHINE_PCB_H_
+      /*
+       * do not redefine breakpoint on armv7
+       */
+      #ifdef __arm__
+        #define _MACHINE_CPUFUNC_H_
+      #endif
     #endif
     #include <sys/user.h>
   #endif
