--- packages/lib/node_modules/node-addon-api/napi.h.orig	2026-11-07 02:27:26 UTC
+++ packages/lib/node_modules/node-addon-api/napi.h
@@ -1144,7 +1144,7 @@ namespace Napi {
 
     TypedArray(napi_env env, napi_value value, napi_typedarray_type type, size_t length);
 
-    static const napi_typedarray_type unknown_array_type = static_cast<napi_typedarray_type>(-1);
+    static inline const napi_typedarray_type unknown_array_type = static_cast<napi_typedarray_type>(-1);
 
     template <typename T>
     static
