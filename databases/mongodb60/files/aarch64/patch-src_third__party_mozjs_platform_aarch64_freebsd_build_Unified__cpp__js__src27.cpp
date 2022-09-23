--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src27.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src27.cpp
@@ -0,0 +1,37 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/Warnings.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Warnings.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Warnings.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/WellKnownAtom.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/WellKnownAtom.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/WellKnownAtom.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/WindowProxy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/WindowProxy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/WindowProxy.cpp defines INITGUID, so it cannot be built in unified mode."
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
