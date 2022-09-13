--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src11.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src11.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "util/AllocPolicy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/AllocPolicy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/AllocPolicy.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/AllocationLogging.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/AllocationLogging.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/AllocationLogging.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/CompleteFile.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/CompleteFile.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/CompleteFile.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/DumpFunctions.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/DumpFunctions.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/DumpFunctions.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/NativeStack.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/NativeStack.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/NativeStack.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/Printf.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/Printf.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/Printf.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
