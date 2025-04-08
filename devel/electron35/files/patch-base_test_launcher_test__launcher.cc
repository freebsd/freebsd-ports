--- base/test/launcher/test_launcher.cc.orig	2025-03-24 20:50:14 UTC
+++ base/test/launcher/test_launcher.cc
@@ -74,6 +74,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
