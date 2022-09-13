--- src/third_party/mozjs/platform/aarch64/freebsd/build/wasm/Unified_cpp_js_src_wasm2.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/wasm/Unified_cpp_js_src_wasm2.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "wasm/WasmGenerator.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmGenerator.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmGenerator.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmInitExpr.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmInitExpr.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmInitExpr.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmInstance.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmInstance.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmInstance.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmIonCompile.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmIonCompile.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmIonCompile.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmJS.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmJS.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmJS.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmModule.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmModule.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmModule.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
