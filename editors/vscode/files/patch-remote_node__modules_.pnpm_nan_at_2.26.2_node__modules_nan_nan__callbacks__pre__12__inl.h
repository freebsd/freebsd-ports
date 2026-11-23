--- remote/node_modules/.pnpm/nan@2.26.2/node_modules/nan/nan_callbacks_pre_12_inl.h.orig	1971-12-10 00:00:00 UTC
+++ remote/node_modules/.pnpm/nan@2.26.2/node_modules/nan/nan_callbacks_pre_12_inl.h
@@ -287,6 +287,10 @@ class PropertyCallbackInfo<v8::Integer> :
   }
 };
 
+inline void* GetExternalValue(v8::Local<v8::External> ext) {
+  return ext->Value();
+}
+
 namespace imp {
 template<typename T>
 class ReturnValueImp : public ReturnValue<T> {
