--- src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src26.cpp.orig	2019-11-14 10:50:10 UTC
+++ src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src26.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/shared/BaselineCompiler-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/BaselineCompiler-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/BaselineCompiler-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/CodeGenerator-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/CodeGenerator-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/CodeGenerator-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/Disassembler-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/Disassembler-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/Disassembler-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/Lowering-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/Lowering-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/Lowering-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jsapi.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jsapi.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jsapi.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jsbool.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jsbool.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jsbool.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
