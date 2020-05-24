--- electron/atom/common/crash_reporter/crash_reporter.cc.orig	2019-04-04 16:09:31 UTC
+++ electron/atom/common/crash_reporter/crash_reporter.cc
@@ -102,7 +102,11 @@ CrashReporter* CrashReporter::GetInstance() {
 #endif
 
 void CrashReporter::StartInstance(const mate::Dictionary& options) {
+#if !defined(OS_BSD)
   auto* reporter = GetInstance();
+#else
+  CrashReporter *reporter = NULL;
+#endif
   if (!reporter)
     return;
 
