--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src35.cpp.orig	2020-11-25 14:27:56 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src35.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/Scope.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Scope.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Scope.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/SelfHosting.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/SelfHosting.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/SelfHosting.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Shape.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Shape.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Shape.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/SharedArrayObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/SharedArrayObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/SharedArrayObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/SharedImmutableStringsCache.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/SharedImmutableStringsCache.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/SharedImmutableStringsCache.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Stack.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Stack.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Stack.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
