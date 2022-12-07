--- Makefile.PL.orig	2021-01-22 08:02:35 UTC
+++ Makefile.PL
@@ -146,7 +146,7 @@ char $f ();
 /* We use char because int might match the return type of a gcc2
    builtin and then its argument prototype would still apply.  */
 char $f ();
-char (*f) ();
+char f;
 
 #ifdef F77_DUMMY_MAIN
 #  ifdef __cplusplus
