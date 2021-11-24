--- base/process/process_util_unittest.cc.orig	2021-07-15 19:13:29 UTC
+++ base/process/process_util_unittest.cc
@@ -1337,11 +1337,11 @@ std::string TestLaunchProcess(const CommandLine& cmdli
   options.fds_to_remap.emplace_back(fds[1], STDOUT_FILENO);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   options.clone_flags = clone_flags;
 #else
   CHECK_EQ(0, clone_flags);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   EXPECT_TRUE(LaunchProcess(cmdline, options).IsValid());
   write_pipe.Close();
