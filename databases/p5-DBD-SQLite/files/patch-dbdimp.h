--- dbdimp.h.orig	Fri Sep  8 06:50:50 2006
+++ dbdimp.h	Tue Sep 12 14:00:36 2006
@@ -105,6 +105,9 @@
 #define newUTF8SVpvn newSVpvn
 #define SvUTF8_on(a) (a)
 #define SvUTF8_off(a) (a)
+#ifndef get_sv
+#define get_sv perl_get_sv
+#endif
 #define sv_utf8_upgrade(a) (a)
 
 #endif
