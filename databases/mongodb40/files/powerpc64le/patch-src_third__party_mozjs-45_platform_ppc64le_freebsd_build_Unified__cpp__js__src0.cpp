--- src/third_party/mozjs-45/platform/ppc64le/freebsd/build/Unified_cpp_js_src0.cpp.orig	2020-11-30 15:55:08 UTC
+++ src/third_party/mozjs-45/platform/ppc64le/freebsd/build/Unified_cpp_js_src0.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "asmjs/AsmJSFrameIterator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/AsmJSFrameIterator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/AsmJSFrameIterator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/AsmJSLink.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/AsmJSLink.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/AsmJSLink.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/AsmJSModule.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/AsmJSModule.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/AsmJSModule.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/AsmJSSignalHandlers.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/AsmJSSignalHandlers.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/AsmJSSignalHandlers.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/AsmJSValidate.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/AsmJSValidate.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/AsmJSValidate.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/WasmGenerator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/WasmGenerator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/WasmGenerator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
