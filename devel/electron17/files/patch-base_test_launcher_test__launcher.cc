--- base/test/launcher/test_launcher.cc.orig	2022-05-11 07:16:46 UTC
+++ base/test/launcher/test_launcher.cc
@@ -63,6 +63,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
