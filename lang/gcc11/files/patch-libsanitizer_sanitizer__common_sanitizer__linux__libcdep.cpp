Patch taken from

https://cgit.freebsd.org/src/commit/?id=96fe7c8ab0f65cf829619abd74ae6c126b21e15f

--- libsanitizer/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2022-11-26 09:47:34 UTC
+++ libsanitizer/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -45,7 +45,9 @@
 
 #if SANITIZER_FREEBSD
 #include <pthread_np.h>
+#include <stdlib.h>
 #include <osreldate.h>
+#include <sys/auxv.h>
 #include <sys/sysctl.h>
 #define pthread_getattr_np pthread_attr_get_np
 #endif
@@ -857,7 +859,14 @@ void ReExec() {
 void ReExec() {
   const char *pathname = "/proc/self/exe";
 
-#if SANITIZER_NETBSD
+#if SANITIZER_FREEBSD
+  char exe_path[PATH_MAX];
+  if (elf_aux_info(AT_EXECPATH, exe_path, sizeof(exe_path)) == 0) {
+    char link_path[PATH_MAX];
+    if (realpath(exe_path, link_path))
+      pathname = link_path;
+  }
+#elif SANITIZER_NETBSD
   static const int name[] = {
       CTL_KERN,
       KERN_PROC_ARGS,
