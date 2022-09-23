--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit15.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit15.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/arm64/vixl/MozInstructions-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/MozInstructions-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/MozInstructions-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/arm64/vixl/Utils-vixl.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/arm64/vixl/Utils-vixl.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/arm64/vixl/Utils-vixl.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/AtomicOperations-shared-jit.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/AtomicOperations-shared-jit.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/AtomicOperations-shared-jit.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/CodeGenerator-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/CodeGenerator-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/CodeGenerator-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/Disassembler-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/Disassembler-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/Disassembler-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/shared/Lowering-shared.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/shared/Lowering-shared.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/shared/Lowering-shared.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
