--- src/cbang/js/v8/Context.cpp.orig	2026-06-01 05:31:12 UTC
+++ src/cbang/js/v8/Context.cpp
@@ -51,11 +51,7 @@ Value Context::eval(const InputSource &src) {
   string filename = src.getName();
   if (!filename.empty()) origin = Value::createString(filename);
 
-#if V8_MAJOR_VERSION < 10
   v8::ScriptOrigin sOrigin(origin);
-#else
-  v8::ScriptOrigin sOrigin(Value::getIso(), origin);
-#endif
 
   // Get script source
   auto source = Value::createString(src.toString());
