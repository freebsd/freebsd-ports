This patch fixes the following error:

In file included from jdk11u-jdk-11.0.24-8-1/src/hotspot/os/bsd/os_perf_bsd.cpp:47:
In file included from /usr/include/sys/user.h:51:
In file included from /usr/include/vm/pmap.h:88:
In file included from /usr/include/machine/pmap.h:48:
In file included from /usr/include/sys/systm.h:46:
/usr/include/machine/cpufunc.h:185:1: error: static declaration of 'breakpoint' follows non-static declaration
  185 | breakpoint(void)
      | ^
/usr/ports/java/openjdk11/work/jdk11u-jdk-11.0.24-8-1/src/hotspot/share/utilities/breakpoint.hpp:31:17: note: previous declaration is here
   31 | extern "C" void breakpoint();



--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2024-11-08 11:24:38 UTC
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -43,6 +43,12 @@
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
