Fix build with FOX >= 1.7.80

--- gap/fox.h.orig	2020-12-27 21:40:54 UTC
+++ gap/fox.h
@@ -35,6 +35,12 @@
 #define FXVERSION(major,minor,release) ((release)+(minor*1000)+(major*100000))
 
 #include <fxdefs.h>
+#if FOXVERSION >= FXVERSION(1, 7, 80)
+#include <fxchar.h>
+#endif
+#if FOXVERSION >= FXVERSION(1, 7, 81)
+#include <fxmath.h>
+#endif
 #include <fxendian.h>
 #include <fxascii.h>
 #include <fxunicode.h>
@@ -121,6 +127,25 @@ constexpr FXTime operator"" _ms(unsigned long long int
 {
   return value * NANOSECONDS_PER_MILLISECOND;
 }
+
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
+#endif
 
 #endif
 
