assembler/ARMAssembler.h:1073:2: error: "The cacheFlush support is missing on this platform."
#error "The cacheFlush support is missing on this platform."
 ^

Obtained from: www/webkit-gtk3/files/patch-Source__JavaScriptCore__assembler__ARMAssembler.h

--- src/qt/qtwebkit/Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2016-01-08 10:07:46 UTC
+++ src/qt/qtwebkit/Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1069,6 +1069,8 @@ namespace JSC {
             UNUSED_PARAM(size);
 #elif OS(QNX)
             msync(code, size, MS_INVALIDATE_ICACHE);
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
