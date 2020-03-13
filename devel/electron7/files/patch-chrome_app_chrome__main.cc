--- chrome/app/chrome_main.cc.orig	2019-12-12 12:39:04 UTC
+++ chrome/app/chrome_main.cc
@@ -101,11 +101,11 @@ int ChromeMain(int argc, const char** argv) {
   MainThreadStackSamplingProfiler scoped_sampling_profiler;
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
   int rv = content::ContentMain(params);
 
