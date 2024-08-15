--- base/process/launch_posix.cc.orig	2024-06-18 21:43:17 UTC
+++ base/process/launch_posix.cc
@@ -66,6 +66,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
