--- chrome/app/chrome_main.cc.orig	2021-04-14 01:08:37 UTC
+++ chrome/app/chrome_main.cc
@@ -130,12 +130,12 @@ int ChromeMain(int argc, const char** argv) {
   MainThreadStackSamplingProfiler scoped_sampling_profiler;
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
   int rv = content::ContentMain(params);
