--- src/packer.h.orig	2013-09-30 15:51:00 UTC
+++ src/packer.h
@@ -238,7 +238,7 @@ protected:
     void addLoader(C,C,C,C,C,C,C,C); void addLoader(C,C,C,C,C,C,C,C,C);
     void addLoader(C,C,C,C,C,C,C,C,C,C);
 #undef C
-#if 1 && (ACC_CC_CLANG || (ACC_CC_GNUC >= 0x040100))
+#if 0 && (ACC_CC_CLANG || (ACC_CC_GNUC >= 0x040100))
     void __acc_cdecl_va addLoaderVA(const char *s, ...) __attribute__((__sentinel__));
 #else
     void __acc_cdecl_va addLoaderVA(const char *s, ...);
