--- dbdimp.h.orig	2021-06-05 16:28:51 UTC
+++ dbdimp.h
@@ -222,6 +222,9 @@ newUTF8SVpvn(char *s, STRLEN len) {
 #define newUTF8SVpvn newSVpvn
 #define SvUTF8_on(a) (a)
 #define SvUTF8_off(a) (a)
+#ifndef get_sv
+#define get_sv perl_get_sv
+#endif
 #define sv_utf8_upgrade(a) (a)
 
 #endif /* #ifdef SvUTF8_on */
