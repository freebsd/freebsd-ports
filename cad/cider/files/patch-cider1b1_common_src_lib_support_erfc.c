--- cider1b1/common/src/lib/support/erfc.c.orig	1994-01-29 19:29:27 UTC
+++ cider1b1/common/src/lib/support/erfc.c
@@ -10,6 +10,7 @@ Author:	1987 Kartikeya Mayaram, U. C. Be
 
 /* erfc computes the erfc(x) the code is from sedan's derfc.f */
 
+#ifdef HAS_NO_ERFC
 double erfc ( x )
 double x;
 {
@@ -46,4 +47,4 @@ double x;
         return( 1.0 - sum2 );
     }
 }
-
+#endif
