--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src31.cpp.orig	2020-11-25 14:27:56 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src31.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/Id.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Id.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Id.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Initialization.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Initialization.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Initialization.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Iteration.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Iteration.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Iteration.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/JSCompartment.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/JSCompartment.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/JSCompartment.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/JSContext.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/JSContext.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/JSContext.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/JSFunction.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/JSFunction.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/JSFunction.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
