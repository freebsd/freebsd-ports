Fix build with FOX 1.7.80

--- src/gmdefs.h.orig	2020-12-27 21:40:54 UTC
+++ src/gmdefs.h
@@ -93,5 +93,27 @@ extern const FXchar * fxtr(const FXchar *) FX_FORMAT(1
 // Best Image Scaler in FXImage
 #define FOX_SCALE_BEST 2
 
+#if FOXVERSION >= FXVERSION(1, 7, 80)
+#include <utility>
+#define FX_ALIAS_SPEC(SPECS, NEW_NAME, ...)                      \
+  template <typename... Args>                                    \
+  SPECS auto NEW_NAME(Args &&... args)                           \
+    noexcept(noexcept(__VA_ARGS__(std::forward<Args>(args)...))) \
+    -> decltype(__VA_ARGS__(std::forward<Args>(args)...)) {      \
+    return __VA_ARGS__(std::forward<Args>(args)...);             \
+  }
+
+#define FX_ALIAS(NEW_NAME, ...)                                  \
+  FX_ALIAS_SPEC(inline, NEW_NAME, __VA_ARGS__)
+
+FX_ALIAS(compare, FXString::compare)
+FX_ALIAS(comparecase, FXString::comparecase)
+FX_ALIAS(compareversion, FXString::comparenatural)
+#define FXISFOLLOWUTF8 followUTF8
+#define FXISLEADUTF16 leadUTF16
+#define FXISFOLLOWUTF16 followUTF16
+#define FXISSEQUTF16 seqUTF16
+#endif
+
 #endif
 
