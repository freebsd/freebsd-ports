--- src/third_party/mozjs/platform/aarch64/freebsd/build/gc/Unified_cpp_js_src_gc3.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/gc/Unified_cpp_js_src_gc3.cpp
@@ -0,0 +1,10 @@
+#define MOZ_UNIFIED_BUILD
+#include "gc/Zone.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Zone.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Zone.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
