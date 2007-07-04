--- src/packer.h.orig	2007-07-04 17:39:57.000000000 +0000
+++ src/packer.h	2007-07-04 17:40:14.000000000 +0000
@@ -235,7 +235,7 @@
     void addLoader(C,C,C,C,C,C,C,C); void addLoader(C,C,C,C,C,C,C,C,C);
     void addLoader(C,C,C,C,C,C,C,C,C,C);
 #undef C
-#if 1 && (ACC_CC_GNUC >= 0x040100)
+#if 0 && (ACC_CC_GNUC >= 0x040100)
     void __acc_cdecl_va addLoaderVA(const char *s, ...) __attribute__((__sentinel__));
 #else
     void __acc_cdecl_va addLoaderVA(const char *s, ...);
