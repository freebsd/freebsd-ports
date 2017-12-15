--- rpython/rlib/rvmprof/src/shared/machine.c.orig	2017-10-03 10:49:20 UTC
+++ rpython/rlib/rvmprof/src/shared/machine.c
@@ -28,7 +28,7 @@ const char * vmp_machine_os_name(void)
 #elif __linux__
     return "linux";
 #elif __FreeBSD__
-    return "freebsd"
+    return "freebsd";
 #else
     #error "Unknown compiler"
 #endif
