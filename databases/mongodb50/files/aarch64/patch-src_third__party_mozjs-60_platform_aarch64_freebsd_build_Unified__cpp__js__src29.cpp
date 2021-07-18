--- src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src29.cpp.orig	2019-11-14 10:50:10 UTC
+++ src/third_party/mozjs-60/platform/aarch64/freebsd/build/Unified_cpp_js_src29.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "proxy/Wrapper.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/Wrapper.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/Wrapper.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "threading/Mutex.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "threading/Mutex.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "threading/Mutex.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
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
\ No newline at end of file
