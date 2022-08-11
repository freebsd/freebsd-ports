--- src/cbang/js/v8/Context.cpp.orig	2021-08-10 22:46:49 UTC
+++ src/cbang/js/v8/Context.cpp
@@ -50,7 +50,12 @@ Value Context::eval(const InputSource &src) {
   v8::Local<v8::String> origin;
   string filename = src.getName();
   if (!filename.empty()) origin = Value::createString(filename);
+
+#if V8_MAJOR_VERSION < 10
   v8::ScriptOrigin sOrigin(origin);
+#else
+  v8::ScriptOrigin sOrigin(Value::getIso(), origin);
+#endif
 
   // Get script source
   auto source = Value::createString(src.toString());
