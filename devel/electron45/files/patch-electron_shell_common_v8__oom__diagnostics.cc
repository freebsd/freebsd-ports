--- electron/shell/common/v8_oom_diagnostics.cc.orig	2026-08-16 12:17:14 UTC
+++ electron/shell/common/v8_oom_diagnostics.cc
@@ -15,7 +15,7 @@ namespace electron::v8_oom {
 
 namespace electron::v8_oom {
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 
 namespace {
 
@@ -140,6 +140,6 @@ void RecordJsStack(v8::Isolate*, std::string_view) {}
 void RecordErrorDetails(v8::Isolate*, const char*, const v8::OOMDetails&) {}
 void RecordJsStack(v8::Isolate*, std::string_view) {}
 
-#endif  // !IS_MAS_BUILD()
+#endif  // !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 
 }  // namespace electron::v8_oom
