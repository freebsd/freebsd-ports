--- src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src9.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/Unified_cpp_js_src9.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "proxy/DOMProxy.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "proxy/DOMProxy.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "proxy/DOMProxy.cpp defines INITGUID, so it cannot be built in unified mode."
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
\ No newline at end of file
