--- src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src5.cpp.orig	2019-01-18 22:48:18 UTC
+++ src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src5.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "frontend/ParseNode.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/ParseNode.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/ParseNode.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/TokenStream.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/TokenStream.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/TokenStream.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Allocator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Allocator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Allocator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Barrier.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Barrier.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Barrier.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/GCTrace.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/GCTrace.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/GCTrace.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Iteration.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Iteration.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Iteration.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
