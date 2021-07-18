--- base/test/launcher/test_launcher.cc.orig	2021-04-14 01:08:36 UTC
+++ base/test/launcher/test_launcher.cc
@@ -58,6 +58,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
@@ -599,7 +600,7 @@ ChildProcessResults DoLaunchChildTestProcess(
 #if !defined(OS_FUCHSIA)
   options.new_process_group = true;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   options.kill_on_parent_death = true;
 #endif
 
@@ -1516,7 +1517,7 @@ bool TestLauncher::Init(CommandLine* command_line) {
   results_tracker_.AddGlobalTag("OS_IOS");
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   results_tracker_.AddGlobalTag("OS_LINUX");
 #endif
 
