$FreeBSD$

--- ../../deploy/src/plugin/solaris/jvm_exec/java_vm.c.orig	Thu Jul  6 17:10:12 2006
+++ ../../deploy/src/plugin/solaris/jvm_exec/java_vm.c	Thu Jul  6 17:10:12 2006
@@ -157,7 +157,7 @@
     libjvm = dlopen(jvmpath, RTLD_NOW + RTLD_GLOBAL);
   
     if (libjvm == NULL) {
-        snprintf(jvmpath, sizeof jvmpath, "%s/lib/"LIBARCH"/%s", java_home, libname);
+        snprintf(jvmpath, sizeof jvmpath, "%s/lib/"LIBARCH"/server/%s", java_home, libname);
         libjvm = dlopen(jvmpath, RTLD_NOW + RTLD_GLOBAL);
     }
 
