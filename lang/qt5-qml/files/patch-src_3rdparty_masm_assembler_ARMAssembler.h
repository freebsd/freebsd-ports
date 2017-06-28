--- src/3rdparty/masm/assembler/ARMAssembler.h.orig	2017-02-02 10:26:18 UTC
+++ src/3rdparty/masm/assembler/ARMAssembler.h
@@ -1069,6 +1069,8 @@ namespace JSC {
             UNUSED_PARAM(size);
 #elif OS(QNX)
             msync(code, size, MS_INVALIDATE_ICACHE);
+#elif OS(FREEBSD) && COMPILER(CLANG)
+            __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
