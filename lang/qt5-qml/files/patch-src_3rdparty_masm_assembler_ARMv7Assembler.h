--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2016-09-12 04:21:49 UTC
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2311,6 +2311,8 @@ public:
         UNUSED_PARAM(code);
         UNUSED_PARAM(size);
 #endif
+#elif OS(FREEBSD) && COMPILER(CLANG)
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
