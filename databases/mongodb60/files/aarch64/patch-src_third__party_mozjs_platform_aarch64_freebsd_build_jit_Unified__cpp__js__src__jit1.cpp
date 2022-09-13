--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit1.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit1.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/BaselineCodeGen.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineCodeGen.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineCodeGen.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineDebugModeOSR.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineDebugModeOSR.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineDebugModeOSR.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineFrame.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineFrame.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineFrame.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineFrameInfo.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineFrameInfo.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineFrameInfo.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineIC.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineIC.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineIC.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/BaselineJIT.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/BaselineJIT.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/BaselineJIT.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
