--- dbdimp.h.orig	Sat Sep 11 00:24:28 2004
+++ dbdimp.h	Mon Dec 27 16:37:25 2004
@@ -99,6 +99,10 @@
 #define newUTF8SVpv newSVpv
 #define newUTF8SVpvn newSVpvn
 #define SvUTF8_on(a) (a)
+#define SvUTF8_off(a) (a)
+#ifndef get_sv
+#define get_sv perl_get_sv
+#endif
 #define sv_utf8_upgrade(a) (a)
 
 #endif
