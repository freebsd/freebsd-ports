--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src5.cpp.orig	2020-11-24 21:44:47 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src5.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "ds/MemoryProtectionExceptionHandler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "ds/MemoryProtectionExceptionHandler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "ds/MemoryProtectionExceptionHandler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/BytecodeCompiler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/BytecodeCompiler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/BytecodeCompiler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/BytecodeEmitter.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/BytecodeEmitter.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/BytecodeEmitter.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/FoldConstants.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/FoldConstants.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/FoldConstants.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/NameFunctions.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/NameFunctions.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/NameFunctions.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/ParseNode.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/ParseNode.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/ParseNode.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
