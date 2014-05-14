--- ./src/support/solaris/xlocale.c.orig	2014-01-16 17:58:45.000000000 +0100
+++ ./src/support/solaris/xlocale.c	2014-05-06 15:50:38.219287659 +0200
@@ -26,7 +26,7 @@
 #include "mbsnrtowcs.inc"
 #include "wcsnrtombs.inc"
       
-size_t __mb_cur_max(locale_t __l) {
+size_t __mb_cur_max_l(locale_t __l) {
   FIX_LOCALE(__l);
   return (__l->lc_ctype->cmapp->cm_mb_cur_max);
 }
