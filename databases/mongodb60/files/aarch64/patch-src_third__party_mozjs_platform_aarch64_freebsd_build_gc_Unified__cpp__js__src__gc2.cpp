--- src/third_party/mozjs/platform/aarch64/freebsd/build/gc/Unified_cpp_js_src_gc2.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/gc/Unified_cpp_js_src_gc2.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "gc/Scheduling.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Scheduling.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Scheduling.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Statistics.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Statistics.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Statistics.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Tracer.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Tracer.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Tracer.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/Verifier.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/Verifier.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/Verifier.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/WeakMap.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/WeakMap.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/WeakMap.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "gc/WeakMapPtr.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "gc/WeakMapPtr.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "gc/WeakMapPtr.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
