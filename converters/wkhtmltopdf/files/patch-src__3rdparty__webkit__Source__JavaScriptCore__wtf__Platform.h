--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2020-11-08 17:05:56.503694000 +0100
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h	2020-11-08 17:06:42.105176000 +0100
@@ -1003,7 +1003,9 @@
     || CPU(SPARC64) \
     || CPU(S390X) \
     || CPU(PPC64) \
-    || CPU(MIPS64)
+    || CPU(MIPS64) \
+    || defined(__aarch64__) \
+    || defined(__riscv)
 #define WTF_USE_JSVALUE64 1
 #else
 #define WTF_USE_JSVALUE32_64 1
