--- gjs/jsapi-class.h.orig	2020-09-12 19:34:36 UTC
+++ gjs/jsapi-class.h
@@ -77,11 +77,11 @@ bool gjs_define_property_dynamic(JSContext       *cx,
  *                              do_base_typecheck and priv_from_js
  */
 #define GJS_DEFINE_PRIV_FROM_JS(type, klass)                                   \
-    GJS_ALWAYS_INLINE [[nodiscard]] [[maybe_unused]] static inline bool        \
+    GJS_ALWAYS_INLINE static inline bool        \
     do_base_typecheck(JSContext* cx, JS::HandleObject obj, bool throw_error) { \
         return gjs_typecheck_instance(cx, obj, &klass, throw_error);           \
     }                                                                          \
-    GJS_ALWAYS_INLINE [[nodiscard]] static inline type* priv_from_js(          \
+    GJS_ALWAYS_INLINE static inline type* priv_from_js(          \
         JSContext* cx, JS::HandleObject obj) {                                 \
         return static_cast<type*>(                                             \
             JS_GetInstancePrivate(cx, obj, &klass, nullptr));                  \
