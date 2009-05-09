--- main/gbx/gbx_math.h	2009-05-08 17:35:50.000000000 -0500
+++ main/gbx/gbx_math.h	2009-05-08 17:36:10.000000000 -0500
@@ -47,9 +47,6 @@
 #if defined(OS_FREEBSD) || defined(OS_OPENBSD)
 double exp10(double x);
 double log2(double x);
-#endif
-
-#ifdef OS_OPENBSD
 double exp2(double x);
 long double log10l(long double x);
 long double fabsl(long double x);
