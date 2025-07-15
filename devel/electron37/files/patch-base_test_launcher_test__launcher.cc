--- base/test/launcher/test_launcher.cc.orig	2025-04-22 20:15:27 UTC
+++ base/test/launcher/test_launcher.cc
@@ -73,6 +73,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
