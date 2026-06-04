--- remote/node_modules/nan/nan_callbacks_12_inl.h.orig	2026-06-04 08:41:57 UTC
+++ remote/node_modules/nan/nan_callbacks_12_inl.h
@@ -178,14 +178,27 @@ class PropertyCallbackInfo {
   NAN_DISALLOW_ASSIGN_COPY_MOVE(PropertyCallbackInfo)
 };
 
+// Gated on V8_EXTERNAL_POINTER_TAG_COUNT (defined alongside the tagged
+// Value() API) rather than a V8_MAJOR_VERSION cutoff, since Node and
+// Chromium/Electron ship divergent V8 snapshots under the same major.
+// Tag must match the one used by imp::NewExternal.
+inline void* GetExternalValue(v8::Local<v8::External> ext) {
+#ifdef V8_EXTERNAL_POINTER_TAG_COUNT
+  return ext->Value(v8::kExternalPointerTypeTagDefault);
+#else
+  return ext->Value();
+#endif
+}
+
 namespace imp {
+
 static
 void FunctionCallbackWrapper(const v8::FunctionCallbackInfo<v8::Value> &info) {
   v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
   FunctionCallback callback = reinterpret_cast<FunctionCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kFunctionIndex)
-          .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kFunctionIndex)
+          .As<v8::Value>().As<v8::External>())));
   FunctionCallbackInfo<v8::Value>
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   callback(cbinfo);
@@ -203,8 +216,8 @@ void GetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   GetterCallback callback = reinterpret_cast<GetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kGetterIndex)
-          .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kGetterIndex)
+          .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -221,8 +234,8 @@ void SetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   SetterCallback callback = reinterpret_cast<SetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kSetterIndex)
-          .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kSetterIndex)
+          .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), value, cbinfo);
 }
 
@@ -240,8 +253,8 @@ void GetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   GetterCallback callback = reinterpret_cast<GetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kGetterIndex)
-          .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kGetterIndex)
+          .As<v8::Value>().As<v8::External>())));
   callback(property, cbinfo);
 }
 
@@ -258,8 +271,8 @@ void SetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   SetterCallback callback = reinterpret_cast<SetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kSetterIndex)
-          .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kSetterIndex)
+          .As<v8::Value>().As<v8::External>())));
   callback(property, value, cbinfo);
 }
 
@@ -282,8 +295,8 @@ v8::Intercepted PropertyGetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyGetterCallback callback = reinterpret_cast<PropertyGetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyGetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -300,8 +313,8 @@ v8::Intercepted PropertySetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertySetterCallback callback = reinterpret_cast<PropertySetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertySetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(property.As<v8::String>(), value, cbinfo);
 }
 
@@ -320,8 +333,8 @@ void PropertyGetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyGetterCallback callback = reinterpret_cast<PropertyGetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyGetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -338,8 +351,8 @@ void PropertySetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertySetterCallback callback = reinterpret_cast<PropertySetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertySetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), value, cbinfo);
 }
 
@@ -357,8 +370,8 @@ void PropertyEnumeratorCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyEnumeratorCallback callback =
       reinterpret_cast<PropertyEnumeratorCallback>(reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyEnumeratorIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyEnumeratorIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(cbinfo);
 }
 
@@ -376,8 +389,8 @@ v8::Intercepted PropertyDeleterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyDeleterCallback callback = reinterpret_cast<PropertyDeleterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyDeleterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -394,8 +407,8 @@ v8::Intercepted PropertyQueryCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyQueryCallback callback = reinterpret_cast<PropertyQueryCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyQueryIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -411,8 +424,8 @@ void PropertyDeleterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyDeleterCallback callback = reinterpret_cast<PropertyDeleterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyDeleterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -428,8 +441,8 @@ void PropertyQueryCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyQueryCallback callback = reinterpret_cast<PropertyQueryCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyQueryIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property.As<v8::String>(), cbinfo);
 }
 
@@ -446,8 +459,8 @@ void PropertyGetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyGetterCallback callback = reinterpret_cast<PropertyGetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyGetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property, cbinfo);
 }
 
@@ -464,8 +477,8 @@ void PropertySetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertySetterCallback callback = reinterpret_cast<PropertySetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertySetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property, value, cbinfo);
 }
 
@@ -482,8 +495,8 @@ void PropertyEnumeratorCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyEnumeratorCallback callback =
       reinterpret_cast<PropertyEnumeratorCallback>(reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyEnumeratorIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyEnumeratorIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(cbinfo);
 }
 
@@ -499,8 +512,8 @@ void PropertyDeleterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyDeleterCallback callback = reinterpret_cast<PropertyDeleterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyDeleterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property, cbinfo);
 }
 
@@ -516,8 +529,8 @@ void PropertyQueryCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   PropertyQueryCallback callback = reinterpret_cast<PropertyQueryCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kPropertyQueryIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(property, cbinfo);
 }
 
@@ -535,8 +548,8 @@ v8::Intercepted IndexGetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexGetterCallback callback = reinterpret_cast<IndexGetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyGetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(index, cbinfo);
 }
 
@@ -553,8 +566,8 @@ v8::Intercepted IndexSetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexSetterCallback callback = reinterpret_cast<IndexSetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertySetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(index, value, cbinfo);
 }
 
@@ -572,8 +585,8 @@ void IndexGetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexGetterCallback callback = reinterpret_cast<IndexGetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyGetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(index, cbinfo);
 }
 
@@ -589,8 +602,8 @@ void IndexSetterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexSetterCallback callback = reinterpret_cast<IndexSetterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertySetterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(index, value, cbinfo);
 }
 
@@ -609,9 +622,9 @@ void IndexEnumeratorCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexEnumeratorCallback callback = reinterpret_cast<IndexEnumeratorCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(
+          Nan::GetExternalValue(obj->GetInternalField(
               kIndexPropertyEnumeratorIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+              .As<v8::Value>().As<v8::External>())));
   callback(cbinfo);
 }
 
@@ -628,8 +641,9 @@ v8::Intercepted IndexDeleterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexDeleterCallback callback = reinterpret_cast<IndexDeleterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyDeleterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(
+              kIndexPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(index, cbinfo);
 }
 
@@ -644,8 +658,8 @@ v8::Intercepted IndexQueryCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexQueryCallback callback = reinterpret_cast<IndexQueryCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyQueryIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>())));
   return callback(index, cbinfo);
 }
 
@@ -660,8 +674,9 @@ void IndexDeleterCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexDeleterCallback callback = reinterpret_cast<IndexDeleterCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyDeleterIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(
+              kIndexPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(index, cbinfo);
 }
 
@@ -676,8 +691,8 @@ void IndexQueryCallbackWrapper(
       cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
   IndexQueryCallback callback = reinterpret_cast<IndexQueryCallback>(
       reinterpret_cast<intptr_t>(
-          obj->GetInternalField(kIndexPropertyQueryIndex)
-              .As<v8::Value>().As<v8::External>()->Value()));
+          Nan::GetExternalValue(obj->GetInternalField(kIndexPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>())));
   callback(index, cbinfo);
 }
 
