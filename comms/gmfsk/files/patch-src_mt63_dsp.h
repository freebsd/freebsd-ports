--- src/mt63/dsp.h.orig	Thu Sep 23 16:05:14 2004
+++ src/mt63/dsp.h	Thu Sep 23 16:09:10 2004
@@ -846,7 +846,7 @@
 	Sum = Elem.Mid + Elem.Out;
 	Diff = Elem.Mid - Elem.Out;
 	Elem.Mid += W2 * Inp - W1 * Sum;
-	Out += W5 * Diff;
+	Elem.Out += W5 * Diff;
 }
 
 template < class typeInp >
@@ -856,8 +856,8 @@
 	double Sum, Diff;
 	Sum = Elem.Mid + Elem.Out;
 	Diff = Elem.Mid - Elem.Out;
-	Elem.Mid += Weight.W2 * Inp - Weigth.W1 * Sum;
-	Out += Weight.W5 * Diff;
+	Elem.Mid += Weight.W2 * Inp - Weight.W1 * Sum;
+	Elem.Out += Weight.W5 * Diff;
 }
 
 /*
