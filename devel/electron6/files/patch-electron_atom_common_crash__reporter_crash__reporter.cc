--- electron/atom/common/crash_reporter/crash_reporter.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/common/crash_reporter/crash_reporter.cc
@@ -127,7 +127,11 @@ CrashReporter* CrashReporter::GetInstance() {
 #endif
 
 void CrashReporter::StartInstance(const mate::Dictionary& options) {
+#if !defined(OS_BSD)
   auto* reporter = GetInstance();
+#else
+  CrashReporter *reporter = NULL;
+#endif
   if (!reporter)
     return;
 
