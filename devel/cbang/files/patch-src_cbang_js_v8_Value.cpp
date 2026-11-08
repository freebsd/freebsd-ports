--- src/cbang/js/v8/Value.cpp.orig	2026-06-01 05:31:12 UTC
+++ src/cbang/js/v8/Value.cpp
@@ -47,7 +47,7 @@ namespace {
 namespace {
   void _callback(const v8::FunctionCallbackInfo<v8::Value> &info) {
     js::Callback &cb =
-      *static_cast<js::Callback *>(v8::External::Cast(*info.Data())->Value());
+      *static_cast<js::Callback *>(v8::External::Cast(*info.Data())->Value(v8::kExternalPointerTypeTagDefault));
 
     try {
       // Convert args
@@ -87,7 +87,7 @@ Value::Value(const js::Function &func) {
   JSImpl::current().add(cb);
 
   v8::Handle<v8::Value> data =
-    v8::External::New(getIso(), (void *)cb.get());
+    v8::External::New(getIso(), (void *)cb.get(), v8::kExternalPointerTypeTagDefault);
   v8::Handle<v8::FunctionTemplate> tmpl =
     v8::FunctionTemplate::New(getIso(), &_callback, data);
   value = tmpl->GetFunction(getCtx()).ToLocalChecked();
