--- base/process/process_util_unittest.cc.orig	2020-05-26 07:48:14 UTC
+++ base/process/process_util_unittest.cc
@@ -1307,11 +1307,11 @@ std::string TestLaunchProcess(const CommandLine& cmdli
   options.fds_to_remap.emplace_back(fds[1], STDOUT_FILENO);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.clone_flags = clone_flags;
 #else
   CHECK_EQ(0, clone_flags);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   EXPECT_TRUE(LaunchProcess(cmdline, options).IsValid());
   write_pipe.Close();
