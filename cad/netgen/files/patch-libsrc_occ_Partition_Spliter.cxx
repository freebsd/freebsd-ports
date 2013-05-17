--- libsrc/occ/Partition_Spliter.cxx.orig	2012-11-09 16:15:02.000000000 +0100
+++ libsrc/occ/Partition_Spliter.cxx	2013-05-12 11:35:38.000000000 +0200
@@ -1169,8 +1169,8 @@
           for (; j<=nbj && ok; ++j) {
             if (Extrema.IsMin(j)) {
 	      hasMin = Standard_True;
-	      ok = Extrema.Value(j) <= tol;  // V6.3
-	      // ok = Extrema.SquareDistance(j) <= tol;  // V6.5
+	      // ok = Extrema.Value(j) <= tol;  // V6.3
+	      ok = Extrema.SquareDistance(j) <= tol;  // V6.5
 	    }
           }
         }
