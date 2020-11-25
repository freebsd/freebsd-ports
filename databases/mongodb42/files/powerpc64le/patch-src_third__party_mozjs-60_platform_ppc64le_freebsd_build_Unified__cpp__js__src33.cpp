--- src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src33.cpp.orig	2020-11-25 14:27:56 UTC
+++ src/third_party/mozjs-60/platform/ppc64le/freebsd/build/Unified_cpp_js_src33.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "vm/ObjectGroup.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ObjectGroup.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ObjectGroup.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/PIC.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/PIC.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/PIC.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/PosixNSPR.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/PosixNSPR.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/PosixNSPR.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Printer.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Printer.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Printer.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/Probes.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/Probes.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/Probes.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "vm/ProxyObject.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "vm/ProxyObject.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "vm/ProxyObject.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
