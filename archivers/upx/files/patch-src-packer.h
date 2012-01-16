--- src/packer.h.orig	2011-12-13 00:08:00.000000000 +0800
+++ src/packer.h	2012-01-06 04:41:44.771998330 +0800
@@ -235,7 +235,7 @@
     void addLoader(C,C,C,C,C,C,C,C); void addLoader(C,C,C,C,C,C,C,C,C);
     void addLoader(C,C,C,C,C,C,C,C,C,C);
 #undef C
-#if 1 && (ACC_CC_CLANG || (ACC_CC_GNUC >= 0x040100))
+#if 0 && (ACC_CC_CLANG || (ACC_CC_GNUC >= 0x040100))
     void __acc_cdecl_va addLoaderVA(const char *s, ...) __attribute__((__sentinel__));
 #else
     void __acc_cdecl_va addLoaderVA(const char *s, ...);
