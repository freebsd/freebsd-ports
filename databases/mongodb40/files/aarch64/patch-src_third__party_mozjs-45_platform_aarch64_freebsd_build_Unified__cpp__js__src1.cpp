--- src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src1.cpp.orig	2019-01-18 22:48:17 UTC
+++ src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src1.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "asmjs/WasmIonCompile.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/WasmIonCompile.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/WasmIonCompile.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "asmjs/WasmStubs.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "asmjs/WasmStubs.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "asmjs/WasmStubs.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "builtin/AtomicsObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/AtomicsObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/AtomicsObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "builtin/Eval.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/Eval.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/Eval.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "builtin/Intl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/Intl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/Intl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "builtin/MapObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/MapObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/MapObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
