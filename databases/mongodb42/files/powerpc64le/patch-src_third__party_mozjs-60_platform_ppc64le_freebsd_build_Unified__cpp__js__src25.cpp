--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src25.cpp.orig	2020-11-25 14:27:55 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src25.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "proxy/OpaqueCrossCompartmentWrapper.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/OpaqueCrossCompartmentWrapper.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/OpaqueCrossCompartmentWrapper.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/Proxy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/Proxy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/Proxy.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/ScriptedProxyHandler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/ScriptedProxyHandler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/ScriptedProxyHandler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "proxy/SecurityWrapper.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/SecurityWrapper.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/SecurityWrapper.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
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
\ No newline at end of file
