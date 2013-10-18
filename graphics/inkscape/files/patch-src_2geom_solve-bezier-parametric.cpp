--- src/2geom/solve-bezier-parametric.cpp.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/2geom/solve-bezier-parametric.cpp	2013-10-17 13:19:47.000000000 +0200
@@ -68,13 +68,20 @@
         break;
     }
 
-    // Otherwise, solve recursively after subdividing control polygon
-    std::vector<Geom::Point> Left(degree + 1);    // New left and right
-    std::vector<Geom::Point> Right(degree + 1);   // control polygons
+    /*
+     * Otherwise, solve recursively after subdividing control polygon
+     * New left and right control polygons
+     */
+    Geom::Point *Left  = new Geom::Point[degree+1];
+    Geom::Point *Right = new Geom::Point[degree+1];
+
     Bezier(w, degree, 0.5, &Left[0], &Right[0]);
     total_subs ++;
     find_parametric_bezier_roots(&Left[0],  degree, solutions, depth + 1);
     find_parametric_bezier_roots(&Right[0], degree, solutions, depth + 1);
+
+    delete[] Left;
+    delete[] Right;
 }
 
 
@@ -191,7 +198,10 @@
        Geom::Point *Left,	/* RETURN left half ctl pts */
        Geom::Point *Right)	/* RETURN right half ctl pts */
 {
-    Geom::Point Vtemp[degree+1][degree+1];
+    Geom::Point **Vtemp = new Geom::Point* [degree+1];
+
+    for (unsigned int i = 0; i < degree+1; ++i)
+        Vtemp[i] = new Geom::Point[degree+1];
 
     /* Copy control points	*/
     std::copy(V, V+degree+1, Vtemp[0]);
@@ -208,7 +218,14 @@
     for (unsigned j = 0; j <= degree; j++)
         Right[j] = Vtemp[degree-j][j];
 
-    return (Vtemp[degree][0]);
+    Geom::Point return_value = Vtemp[degree][0];
+
+    for (unsigned int i = 0; i < degree+1; ++i)
+        delete[] Vtemp[i];
+
+    delete[] Vtemp;
+
+    return return_value;
 }
 
 };
