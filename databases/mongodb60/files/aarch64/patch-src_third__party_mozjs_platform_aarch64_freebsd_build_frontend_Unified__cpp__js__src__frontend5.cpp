--- src/third_party/mozjs/platform/aarch64/freebsd/build/frontend/Unified_cpp_js_src_frontend5.cpp.orig	2022-09-08 14:42:13 UTC
+++ src/third_party/mozjs/platform/aarch64/freebsd/build/frontend/Unified_cpp_js_src_frontend5.cpp
@@ -0,0 +1,55 @@
+#define MOZ_UNIFIED_BUILD
+#include "frontend/ParserAtom.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/ParserAtom.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/ParserAtom.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/PrivateOpEmitter.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/PrivateOpEmitter.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/PrivateOpEmitter.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/PropOpEmitter.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/PropOpEmitter.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/PropOpEmitter.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/SharedContext.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/SharedContext.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/SharedContext.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/SourceNotes.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/SourceNotes.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/SourceNotes.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
+#include "frontend/Stencil.cpp"
+#ifdef PL_ARENA_CONST_ALIGN_MASK
+#error "frontend/Stencil.cpp uses PL_ARENA_CONST_ALIGN_MASK, so it cannot be built in unified mode."
+#undef PL_ARENA_CONST_ALIGN_MASK
+#endif
+#ifdef INITGUID
+#error "frontend/Stencil.cpp defines INITGUID, so it cannot be built in unified mode."
+#undef INITGUID
+#endif
\ No newline at end of file
