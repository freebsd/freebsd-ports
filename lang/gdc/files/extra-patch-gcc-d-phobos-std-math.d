--- gcc/d/phobos/std/math.d.orig	2007-03-09 05:02:35.000000000 +0300
+++ gcc/d/phobos/std/math.d	2009-03-18 05:04:19.000000000 +0300
@@ -638,8 +638,6 @@
  *	)
  */
 
-version (GNU_msvcrt_math) { /* nothing */ } else
-real expm1(real x)		{ return std.c.math.expm1l(x); }
 
 
 /*********************************************************************
@@ -842,7 +840,6 @@
  *	)
  */
 
-real log1p(real x)		{ return std.c.math.log1pl(x); }
 
 /***************************************
  * Calculates the base-2 logarithm of x:
@@ -922,7 +919,6 @@
  *	<tr> <td> &plusmn;&infin;	<td> &plusmn;&infin; <td> no 
  *	)
  */
-real cbrt(real x)		{ return std.c.math.cbrtl(x); }
 
 
 /*******************************
@@ -1066,16 +1062,12 @@
  *
  * <img src="erf.gif" alt="error function">
  */
-version (GNU_msvcrt_math) { /* nothing */ } else
-real erf(real x)		{ return std.c.math.erfl(x); }
 
 /**********************************
  * Returns the complementary error function of x, which is 1 - erf(x).
  *
  * <img src="erfc.gif" alt="complementary error function">
  */
-version (GNU_msvcrt_math) { /* nothing */ } else
-real erfc(real x)		{ return std.c.math.erfcl(x); }
 
 /***********************************
  * Natural logarithm of gamma function.
@@ -1093,12 +1085,6 @@
  *	)
  */
 /* Documentation prepared by Don Clugston */
-real lgamma(real x)
-{
-    return std.c.math.lgammal(x);
-
-    // Use etc.gamma.lgamma for those C systems that are missing it
-}
 
 /***********************************
  *  The Gamma function, $(GAMMA)(x)
@@ -1125,18 +1111,6 @@
  *	$(LINK http://www.netlib.org/cephes/ldoubdoc.html#gamma)
  */
 /* Documentation prepared by Don Clugston */
-version (GNU_Need_tgamma)
-{
-    private import etc.gamma;
-    alias etc.gamma.tgamma tgamma;
-}
-else
-real tgamma(real x)
-{
-    return std.c.math.tgammal(x);
-
-    // Use etc.gamma.tgamma for those C systems that are missing it
-}
 
 /**************************************
  * Returns the value of x rounded upward to the next integer
