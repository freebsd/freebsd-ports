--- ./include/support/solaris/xlocale.h.orig	2014-01-16 17:58:45.000000000 +0100
+++ ./include/support/solaris/xlocale.h	2014-05-06 16:11:11.135199398 +0200
@@ -32,8 +32,8 @@
 
 #define LC_GLOBAL_LOCALE ((locale_t)-1)
 
-size_t __mb_cur_max(locale_t l);
-#define MB_CUR_MAX_L(l) __mb_cur_max(l) 
+size_t __mb_cur_max_l(locale_t l);
+#define MB_CUR_MAX_L(l) __mb_cur_max_l(l) 
 
 locale_t newlocale(int mask, const char * locale, locale_t base);
 void freelocale(locale_t loc);
