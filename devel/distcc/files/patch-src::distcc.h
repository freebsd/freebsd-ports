--- src/distcc.h.orig	Sat Aug 10 21:53:27 2002
+++ src/distcc.h	Sat Aug 10 21:53:41 2002
@@ -43,9 +43,6 @@
 #  define UNUSED(x) x
 #endif				/* !__GNUC__ && !__LCLINT__ */
 
-#ifndef HAVE_SA_FAMILY_T
-typedef int sa_family_t;
-#endif
 
 
 struct dcc_hostdef;
