--- src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src33.cpp.orig	2019-01-18 22:48:18 UTC
+++ src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src33.cpp
@@ -0,0 +1,37 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/Unicode.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Unicode.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Unicode.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Value.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Value.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Value.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/WeakMapPtr.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/WeakMapPtr.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/WeakMapPtr.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Xdr.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Xdr.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Xdr.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
