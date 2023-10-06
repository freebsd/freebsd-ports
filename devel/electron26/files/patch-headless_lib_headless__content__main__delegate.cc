--- headless/lib/headless_content_main_delegate.cc.orig	2023-05-25 00:41:57 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -337,7 +337,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   if (process_type != ::switches::kZygoteProcess) {
     g_headless_crash_client.Pointer()->set_crash_dumps_dir(
         command_line.GetSwitchValuePath(switches::kCrashDumpsDir));
-#if !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
     crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
 #endif  // !BUILDFLAG(IS_WIN)
     crash_keys::SetSwitchesFromCommandLine(command_line, nullptr);
