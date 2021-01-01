--- electron/shell/common/api/atom_api_crash_reporter.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/common/api/atom_api_crash_reporter.cc
@@ -42,6 +42,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 v8::Local<v8::Context> context,
                 void* priv) {
   using gin_util::SetMethod;
+#if !defined(OS_BSD)
   auto reporter = base::Unretained(CrashReporter::GetInstance());
   SetMethod(exports, "start",
             base::BindRepeating(&CrashReporter::Start, reporter));
@@ -58,6 +59,7 @@ void Initialize(v8::Local<v8::Object> exports,
             base::BindRepeating(&CrashReporter::SetUploadToServer, reporter));
   SetMethod(exports, "getUploadToServer",
             base::BindRepeating(&CrashReporter::GetUploadToServer, reporter));
+#endif
 }
 
 }  // namespace
