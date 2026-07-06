--- extensions/copilot/node_modules/node-addon-api/napi.h.orig	2026-06-07 09:13:35 UTC
+++ extensions/copilot/node_modules/node-addon-api/napi.h
@@ -1144,7 +1144,7 @@ namespace Napi {
 
     TypedArray(napi_env env, napi_value value, napi_typedarray_type type, size_t length);
 
-    static const napi_typedarray_type unknown_array_type = static_cast<napi_typedarray_type>(-1);
+    static inline const napi_typedarray_type unknown_array_type = static_cast<napi_typedarray_type>(-1);
 
     template <typename T>
     static
