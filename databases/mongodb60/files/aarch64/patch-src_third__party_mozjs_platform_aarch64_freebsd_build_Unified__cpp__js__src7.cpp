--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src7.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src7.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "builtin/streams/WritableStreamOperations.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/streams/WritableStreamOperations.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/streams/WritableStreamOperations.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "builtin/streams/WritableStreamWriterOperations.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "builtin/streams/WritableStreamWriterOperations.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "builtin/streams/WritableStreamWriterOperations.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "ds/Bitmap.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "ds/Bitmap.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "ds/Bitmap.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "ds/LifoAlloc.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "ds/LifoAlloc.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "ds/LifoAlloc.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "ds/MemoryProtectionExceptionHandler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "ds/MemoryProtectionExceptionHandler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "ds/MemoryProtectionExceptionHandler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jsapi.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jsapi.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jsapi.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
