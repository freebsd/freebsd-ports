--- node_modules/nan/nan_implementation_12_inl.h.orig	2026-06-04 08:39:31 UTC
+++ node_modules/nan/nan_implementation_12_inl.h
@@ -14,6 +14,22 @@ namespace imp {
 
 namespace imp {
 
+// Recent V8 versions (currently Chromium/Electron's V8 snapshot; not yet in
+// any released Node) gained an ExternalPointerTypeTag parameter on
+// v8::External::New().  Detect that API via the V8_EXTERNAL_POINTER_TAG_COUNT
+// macro (defined in <v8-internal.h> alongside the new signature) rather than
+// a V8_MAJOR_VERSION cutoff, since Node and Chromium ship divergent V8
+// snapshots under the same major version.  Externals created via this helper
+// are read back through imp::GetExternalPointer in nan_callbacks_12_inl.h,
+// which uses the matching kExternalPointerTypeTagDefault tag.
+inline v8::Local<v8::External> NewExternal(v8::Isolate* isolate, void* value) {
+#ifdef V8_EXTERNAL_POINTER_TAG_COUNT
+  return v8::External::New(isolate, value, v8::kExternalPointerTypeTagDefault);
+#else
+  return v8::External::New(isolate, value);
+#endif
+}
+
 //=== Array ====================================================================
 
 Factory<v8::Array>::return_t
@@ -76,7 +92,7 @@ Factory<v8::External>::New(void * value) {
 
 Factory<v8::External>::return_t
 Factory<v8::External>::New(void * value) {
-  return v8::External::New(v8::Isolate::GetCurrent(), value);
+  return imp::NewExternal(v8::Isolate::GetCurrent(), value);
 }
 
 //=== Function =================================================================
@@ -92,7 +108,7 @@ Factory<v8::Function>::New( FunctionCallback callback
 
   obj->SetInternalField(
       imp::kFunctionIndex
-    , v8::External::New(isolate, reinterpret_cast<void *>(callback)));
+    , imp::NewExternal(isolate, reinterpret_cast<void *>(callback)));
 
   v8::Local<v8::Value> val = v8::Local<v8::Value>::New(isolate, data);
 
@@ -128,7 +144,7 @@ Factory<v8::FunctionTemplate>::New( FunctionCallback c
 
     obj->SetInternalField(
         imp::kFunctionIndex
-      , v8::External::New(isolate, reinterpret_cast<void *>(callback)));
+      , imp::NewExternal(isolate, reinterpret_cast<void *>(callback)));
     v8::Local<v8::Value> val = v8::Local<v8::Value>::New(isolate, data);
 
     if (!val.IsEmpty()) {
