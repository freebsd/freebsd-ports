Index: js/src/jit/ProcessExecutableMemory.h
--- js/src/jit/ProcessExecutableMemory.h.orig	2022-03-30 19:25:41 UTC
+++ js/src/jit/ProcessExecutableMemory.h
@@ -14,7 +14,7 @@ namespace jit {
 
 // Limit on the number of bytes of executable memory to prevent JIT spraying
 // attacks.
-#if JS_BITS_PER_WORD == 32
+#if JS_BITS_PER_WORD == 32 || defined(__OpenBSD__)
 static const size_t MaxCodeBytesPerProcess = 140 * 1024 * 1024;
 #else
 // This is the largest number which satisfies various alignment static
