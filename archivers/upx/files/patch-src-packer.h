--- src/packer.h.orig	2023-01-30 10:18:06 UTC
+++ src/packer.h
@@ -225,7 +225,7 @@ class Packer { (protected)
     void addLoader(C, C, C, C, C, C, C, C, C);
     void addLoader(C, C, C, C, C, C, C, C, C, C);
 #undef C
-#if (ACC_CC_CLANG || ACC_CC_GNUC)
+#if 0 && (ACC_CC_CLANG || ACC_CC_GNUC)
     void addLoaderVA(const char *s, ...) __attribute__((__sentinel__));
 #else
     void addLoaderVA(const char *s, ...);
