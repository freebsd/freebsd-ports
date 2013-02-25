--- ./src/plugins_3rdparty/umuscle/src/muscle/intmath.cpp.orig	2012-12-26 17:43:44.000000000 +0800
+++ ./src/plugins_3rdparty/umuscle/src/muscle/intmath.cpp	2013-02-25 17:25:06.000000000 +0800
@@ -9,13 +9,6 @@
 	return (PROB) pow(2.0, (double) Score/INTSCALE);
 	}
 
-static const double log2e = log2(exp(1.0));
-
-double lnTolog2(double ln)
-	{
-	return ln*log2e;
-	}
-
 double log2(double x)
 	{
 	if (0 == x)
@@ -27,6 +20,13 @@
 	return log(x)*dInvLn2;
 	}
 
+static const double log2e = log2(exp(1.0));
+
+double lnTolog2(double ln)
+	{
+	return ln*log2e;
+	}
+
 SCORE ProbToScore(PROB Prob)
 	{
 	if (0.0 == Prob)
