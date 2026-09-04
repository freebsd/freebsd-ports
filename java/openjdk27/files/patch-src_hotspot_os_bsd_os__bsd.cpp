--- src/hotspot/os/bsd/os_bsd.cpp.orig	2026-04-22 18:05:58 UTC
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -132,6 +132,10 @@
 #define KINFO_PROC_T   kinfo_proc
 #define KI_RSS         p_vm_rssize
 #elif defined(__FreeBSD__)
+  #if ( defined(__aarch64__) && __FreeBSD_version >= 160000 )
+    // do not redefine "breakpoint"
+    #define _MACHINE_CPUFUNC_H_
+  #endif
 #include <sys/user.h>
 #define KERN_PROC_MIB  KERN_PROC
 #define KINFO_PROC_T   kinfo_proc
@@ -480,7 +484,7 @@ void os::init_system_properties_values() {
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH
