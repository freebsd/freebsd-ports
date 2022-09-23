--- src/third_party/mozjs/platform/aarch64/freebsd/build/irregexp/Unified_cpp_js_src_irregexp2.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/irregexp/Unified_cpp_js_src_irregexp2.cpp
@@ -0,0 +1,19 @@
+#define MOZ_UNIFIED_BUILD
+#include "irregexp/imported/regexp-stack.cc"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "irregexp/imported/regexp-stack.cc uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "irregexp/imported/regexp-stack.cc defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "irregexp/util/UnicodeShim.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "irregexp/util/UnicodeShim.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "irregexp/util/UnicodeShim.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
