--- base/process/launch_posix.cc.orig	2019-09-10 10:42:27 UTC
+++ base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
