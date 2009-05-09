--- main/gbx/gbx_math.c	2009-05-08 17:34:14.000000000 -0500
+++ main/gbx/gbx_math.c	2009-05-08 17:34:45.000000000 -0500
@@ -207,10 +207,6 @@
 	return log(x) / M_LN2;
 }
 
-#endif
-
-#ifdef OS_OPENBSD
-
 double exp2(double x)
 {
 	return pow(2, x);
