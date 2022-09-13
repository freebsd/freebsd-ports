--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src14.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src14.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/BuildId.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/BuildId.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/BuildId.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/BuiltinObjectKind.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/BuiltinObjectKind.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/BuiltinObjectKind.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/BytecodeLocation.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/BytecodeLocation.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/BytecodeLocation.cpp defines INITGUID, so it cannot be built in unified mode."
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
\ No newline at end of file
