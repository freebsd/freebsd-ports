--- src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src29.cpp.orig	2019-01-18 22:48:17 UTC
+++ src/third_party/mozjs-45/platform/aarch64/freebsd/build/Unified_cpp_js_src29.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/ProxyObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ProxyObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ProxyObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ReceiverGuard.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ReceiverGuard.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ReceiverGuard.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/RegExpObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/RegExpObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/RegExpObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/RegExpStatics.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/RegExpStatics.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/RegExpStatics.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Runtime.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Runtime.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Runtime.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/SPSProfiler.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/SPSProfiler.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/SPSProfiler.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
