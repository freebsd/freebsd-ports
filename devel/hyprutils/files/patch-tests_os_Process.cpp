--- tests/os/Process.cpp.orig	2025-11-25 18:53:32 UTC
+++ tests/os/Process.cpp
@@ -2,6 +2,9 @@
 
 #include <gtest/gtest.h>
 
+#include <sys/types.h>
+#include <signal.h>
+
 using namespace Hyprutils::OS;
 
 TEST(OS, process) {
