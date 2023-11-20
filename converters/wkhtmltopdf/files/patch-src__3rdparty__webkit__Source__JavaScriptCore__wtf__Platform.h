--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2018-05-29 06:56:52 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h
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
