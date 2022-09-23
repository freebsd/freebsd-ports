--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit12.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit12.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/WasmBCE.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/WasmBCE.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/WasmBCE.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/XrayJitInfo.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/XrayJitInfo.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/XrayJitInfo.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/Architecture-arm64.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/Architecture-arm64.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/Architecture-arm64.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/Assembler-arm64.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/Assembler-arm64.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/Assembler-arm64.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/Bailouts-arm64.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/Bailouts-arm64.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/Bailouts-arm64.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/CodeGenerator-arm64.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/CodeGenerator-arm64.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/CodeGenerator-arm64.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
