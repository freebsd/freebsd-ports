--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src39.cpp.orig	2020-11-24 21:44:47 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src39.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "wasm/WasmBinaryToText.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmBinaryToText.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmBinaryToText.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmBuiltins.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmBuiltins.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmBuiltins.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmCode.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmCode.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmCode.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmCompartment.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmCompartment.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmCompartment.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmCompile.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmCompile.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmCompile.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmDebug.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmDebug.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmDebug.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
