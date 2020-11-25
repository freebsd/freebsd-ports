--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src28.cpp.orig	2020-11-25 14:27:55 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src28.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/AsyncIteration.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/AsyncIteration.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/AsyncIteration.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/BytecodeUtil.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/BytecodeUtil.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/BytecodeUtil.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Caches.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Caches.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Caches.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/CallNonGenericMethod.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/CallNonGenericMethod.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/CallNonGenericMethod.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/CharacterEncoding.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/CharacterEncoding.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/CharacterEncoding.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/CodeCoverage.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/CodeCoverage.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/CodeCoverage.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
