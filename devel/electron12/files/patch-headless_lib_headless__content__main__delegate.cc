--- headless/lib/headless_content_main_delegate.cc.orig	2021-04-14 01:08:50 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -326,7 +326,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -355,7 +355,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   crash_reporter::InitializeCrashpadWithEmbeddedHandler(
       process_type.empty(), process_type, "", base::FilePath());
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // defined(OS_FUCHSIA)
+#endif  // defined(OS_FUCHSIA) || defined(OS_BSD)
 }
 
 
