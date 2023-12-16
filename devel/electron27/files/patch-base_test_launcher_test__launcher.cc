--- base/test/launcher/test_launcher.cc.orig	2023-10-19 19:57:58 UTC
+++ base/test/launcher/test_launcher.cc
@@ -68,6 +68,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
