--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src26.cpp.orig	2020-11-25 14:27:55 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src26.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "threading/ProtectedData.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "threading/ProtectedData.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "threading/ProtectedData.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "threading/posix/CpuCount.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "threading/posix/CpuCount.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "threading/posix/CpuCount.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "threading/posix/Thread.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "threading/posix/Thread.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "threading/posix/Thread.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "util/AllocPolicy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "util/AllocPolicy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "util/AllocPolicy.cpp defines INITGUID, so it cannot be built in unified mode."
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
