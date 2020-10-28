--- modules/javafx.web/src/main/native/Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2020-09-02 20:39:53 UTC
+++ modules/javafx.web/src/main/native/Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2825,6 +2825,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
