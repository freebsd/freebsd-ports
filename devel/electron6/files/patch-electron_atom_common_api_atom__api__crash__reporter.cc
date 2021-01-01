--- electron/atom/common/api/atom_api_crash_reporter.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/common/api/atom_api_crash_reporter.cc
@@ -35,15 +35,23 @@ struct Converter<CrashReporter::UploadReportResult> {
 namespace {
 
 void AddExtraParameter(const std::string& key, const std::string& value) {
+#if !defined(OS_BSD)
   CrashReporter::GetInstance()->AddExtraParameter(key, value);
+#endif
 }
 
 void RemoveExtraParameter(const std::string& key) {
+#if !defined(OS_BSD)
   CrashReporter::GetInstance()->RemoveExtraParameter(key);
+#endif
 }
 
 std::map<std::string, std::string> GetParameters() {
+#if !defined(OS_BSD)
   return CrashReporter::GetInstance()->GetParameters();
+#else
+  return std::map<std::string, std::string>();
+#endif
 }
 
 void Initialize(v8::Local<v8::Object> exports,
@@ -51,6 +59,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 v8::Local<v8::Context> context,
                 void* priv) {
   mate::Dictionary dict(context->GetIsolate(), exports);
+#if !defined(OS_BSD)
   auto reporter = base::Unretained(CrashReporter::GetInstance());
   dict.SetMethod("start", base::Bind(&CrashReporter::Start, reporter));
   dict.SetMethod("addExtraParameter", &AddExtraParameter);
@@ -62,6 +71,7 @@ void Initialize(v8::Local<v8::Object> exports,
                  base::Bind(&CrashReporter::SetUploadToServer, reporter));
   dict.SetMethod("getUploadToServer",
                  base::Bind(&CrashReporter::GetUploadToServer, reporter));
+#endif
 }
 
 }  // namespace
