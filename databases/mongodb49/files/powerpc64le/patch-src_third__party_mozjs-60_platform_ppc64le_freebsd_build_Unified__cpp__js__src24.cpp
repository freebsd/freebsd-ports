--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src24.cpp.orig	2020-11-24 21:44:47 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src24.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "jsfriendapi.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jsfriendapi.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jsfriendapi.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "jsnum.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "jsnum.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "jsnum.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "perf/jsperf.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "perf/jsperf.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "perf/jsperf.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/BaseProxyHandler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/BaseProxyHandler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/BaseProxyHandler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/CrossCompartmentWrapper.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/CrossCompartmentWrapper.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/CrossCompartmentWrapper.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/DeadObjectProxy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/DeadObjectProxy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/DeadObjectProxy.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
