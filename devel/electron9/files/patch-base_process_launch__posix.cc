--- base/process/launch_posix.cc.orig	2020-05-26 07:48:14 UTC
+++ base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
