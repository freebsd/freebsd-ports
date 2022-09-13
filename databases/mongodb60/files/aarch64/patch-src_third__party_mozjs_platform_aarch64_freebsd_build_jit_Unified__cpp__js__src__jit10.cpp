--- src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit10.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/jit/Unified_cpp_js_src_jit10.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jit/ScalarReplacement.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/ScalarReplacement.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/ScalarReplacement.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/Sink.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/Sink.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/Sink.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/Snapshots.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/Snapshots.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/Snapshots.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/TrialInlining.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/TrialInlining.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/TrialInlining.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/TypePolicy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/TypePolicy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/TypePolicy.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jit/VMFunctions.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jit/VMFunctions.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jit/VMFunctions.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
