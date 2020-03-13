--- electron/shell/common/crash_reporter/crash_reporter.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/common/crash_reporter/crash_reporter.cc
@@ -128,7 +128,11 @@ CrashReporter* CrashReporter::GetInstance() {
 #endif
 
 void CrashReporter::StartInstance(const mate::Dictionary& options) {
+#if !defined(OS_BSD)
   auto* reporter = GetInstance();
+#else
+  CrashReporter *reporter = NULL;
+#endif
   if (!reporter)
     return;
 
