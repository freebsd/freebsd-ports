--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit3.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit3.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/CodeGenerator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/CodeGenerator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/CodeGenerator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/CompileWrappers.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/CompileWrappers.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/CompileWrappers.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/Disassemble.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/Disassemble.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/Disassemble.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/EdgeCaseAnalysis.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/EdgeCaseAnalysis.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/EdgeCaseAnalysis.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/EffectiveAddressAnalysis.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/EffectiveAddressAnalysis.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/EffectiveAddressAnalysis.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/ExecutableAllocator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/ExecutableAllocator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/ExecutableAllocator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
