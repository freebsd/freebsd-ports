--- media/base/user_input_monitor_unittest.cc.orig	2023-02-01 18:43:22 UTC
+++ media/base/user_input_monitor_unittest.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
@@ -49,7 +49,7 @@ class UserInputMonitorTest : public testing::Test {
 }  // namespace
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
@@ -72,7 +72,7 @@ TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
 }
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecificWithMapping) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
