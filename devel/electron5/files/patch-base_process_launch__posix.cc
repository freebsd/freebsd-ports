--- base/process/launch_posix.cc.orig	2019-04-08 08:32:37 UTC
+++ base/process/launch_posix.cc
@@ -64,6 +64,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
