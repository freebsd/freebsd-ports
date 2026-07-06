--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2026-01-23 03:03:41 UTC
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -35,6 +35,10 @@
   #include <mach/task_info.h>
 #else
 # if !defined(__NetBSD__)
+  #if ( defined (__aarch64__) && __FreeBSD_version >= 160000 )
+    // do not redefine breakpoint
+    #define _MACHINE_CPUFUNC_H_
+  #endif
   #include <sys/user.h>
 # endif
   #include <sys/sched.h>
