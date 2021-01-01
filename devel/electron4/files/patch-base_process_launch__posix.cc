--- base/process/launch_posix.cc.orig	2019-03-15 06:36:56 UTC
+++ base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #include "base/feature_list.h"
 #else
 extern char** environ;
+#pragma weak environ
 #endif
 
 namespace base {
