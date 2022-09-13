--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit0.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit0.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/AliasAnalysis.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/AliasAnalysis.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/AliasAnalysis.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/AlignmentMaskAnalysis.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/AlignmentMaskAnalysis.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/AlignmentMaskAnalysis.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BacktrackingAllocator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BacktrackingAllocator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BacktrackingAllocator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/Bailouts.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/Bailouts.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/Bailouts.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineBailouts.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineBailouts.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineBailouts.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineCacheIRCompiler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineCacheIRCompiler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineCacheIRCompiler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
