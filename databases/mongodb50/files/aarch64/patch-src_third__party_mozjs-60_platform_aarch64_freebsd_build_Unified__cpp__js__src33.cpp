--- src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src33.cpp.orig	2019-11-14 10:50:10 UTC
+++ src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src33.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/EnvironmentObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/EnvironmentObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/EnvironmentObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ErrorObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ErrorObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ErrorObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ErrorReporting.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ErrorReporting.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ErrorReporting.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ForOfIterator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ForOfIterator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ForOfIterator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/GeckoProfiler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/GeckoProfiler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/GeckoProfiler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/GeneratorObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/GeneratorObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/GeneratorObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
