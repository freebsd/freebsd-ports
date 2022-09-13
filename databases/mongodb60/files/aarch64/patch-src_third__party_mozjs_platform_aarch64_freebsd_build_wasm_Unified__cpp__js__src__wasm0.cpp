--- src/third_party/mozjs/platform/aarch64/freebsd/build/wasm/Unified_cpp_js_src_wasm0.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/wasm/Unified_cpp_js_src_wasm0.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "wasm/AsmJS.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/AsmJS.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/AsmJS.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/TypedObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/TypedObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/TypedObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmBaselineCompile.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmBaselineCompile.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmBaselineCompile.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "wasm/WasmBinary.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "wasm/WasmBinary.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "wasm/WasmBinary.cpp defines INITGUID, so it cannot be built in unified mode."
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
\ No newline at end of file
