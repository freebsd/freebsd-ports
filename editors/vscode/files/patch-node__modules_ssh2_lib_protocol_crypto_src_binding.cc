--- node_modules/ssh2/lib/protocol/crypto/src/binding.cc.orig	2026-04-11 09:21:27 UTC
+++ node_modules/ssh2/lib/protocol/crypto/src/binding.cc
@@ -86,7 +86,7 @@ class ChaChaPolyCipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -420,7 +420,7 @@ class AESGCMCipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -661,7 +661,7 @@ class GenericCipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1058,7 +1058,7 @@ class ChaChaPolyDecipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1486,7 +1486,7 @@ class AESGCMDecipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1738,7 +1738,7 @@ class GenericDecipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
