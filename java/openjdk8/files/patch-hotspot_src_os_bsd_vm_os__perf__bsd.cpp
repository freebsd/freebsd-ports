--- hotspot/src/os/bsd/vm/os_perf_bsd.cpp.orig	2021-04-26 16:00:48 UTC
+++ hotspot/src/os/bsd/vm/os_perf_bsd.cpp
@@ -43,6 +43,15 @@
   #include <mach/task_info.h>
 #else
   #ifndef __NetBSD__
+    #ifdef __FreeBSD__
+      /*
+       * Older versions of FreeBSD accidentally include machine/frame.h from
+       * sys/user.h header. Disable this bad behavior, because a
+       * 'non-standard' structure 'frame' conflict with an internal structure
+       * with the same name.
+       */
+      #define _MACHINE_PCB_H_
+    #endif
     #include <sys/user.h>
   #endif
   #include <sys/sched.h>
