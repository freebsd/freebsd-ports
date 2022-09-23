--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit14.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit14.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/arm64/vixl/Cpu-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/Cpu-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/Cpu-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/Decoder-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/Decoder-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/Decoder-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/Instructions-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/Instructions-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/Instructions-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/MacroAssembler-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/MacroAssembler-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/MacroAssembler-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/MozAssembler-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/MozAssembler-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/MozAssembler-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/MozCpu-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/MozCpu-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/MozCpu-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
