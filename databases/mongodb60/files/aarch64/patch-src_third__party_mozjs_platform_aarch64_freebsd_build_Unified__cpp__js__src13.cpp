--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src13.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src13.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/ArrayBufferObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ArrayBufferObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ArrayBufferObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ArrayBufferObjectMaybeShared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ArrayBufferObjectMaybeShared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ArrayBufferObjectMaybeShared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ArrayBufferViewObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ArrayBufferViewObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ArrayBufferViewObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/AsyncFunction.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/AsyncFunction.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/AsyncFunction.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/AsyncIteration.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/AsyncIteration.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/AsyncIteration.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/BigIntType.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/BigIntType.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/BigIntType.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
