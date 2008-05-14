--- intmath.cpp.orig	Tue Nov 30 05:09:50 2004
+++ intmath.cpp	Mon Jul  4 07:49:45 2005
@@ -8,13 +8,6 @@
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
@@ -24,6 +17,13 @@
 // Multiply by inverse of log(2) just in case multiplication
 // is faster than division.
 	return log(x)*dInvLn2;
+	}
+
+static const double log2e = log2(exp(1.0));
+
+double lnTolog2(double ln)
+	{
+	return ln*log2e;
 	}
 
 SCORE ProbToScore(PROB Prob)
