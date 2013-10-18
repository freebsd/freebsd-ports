--- src/2geom/basic-intersection.cpp.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/2geom/basic-intersection.cpp	2013-10-17 13:17:08.000000000 +0200
@@ -64,7 +64,12 @@
 void split(vector<Point> const &p, double t, 
            vector<Point> &left, vector<Point> &right) {
     const unsigned sz = p.size();
-    Geom::Point Vtemp[sz][sz];
+    
+    Geom::Point **Vtemp = new Geom::Point* [sz];
+
+    for (unsigned int i = 0; i < sz; ++i) {
+        Vtemp[i] = new Geom::Point[sz];
+    }
 
     /* Copy control points	*/
     std::copy(p.begin(), p.end(), Vtemp[0]);
@@ -82,6 +87,11 @@
         left[j]  = Vtemp[j][0];
     for (unsigned j = 0; j < sz; j++)
         right[j] = Vtemp[sz-1-j][j];
+
+    for (unsigned int i = 0; i < sz; ++i)
+        delete[] Vtemp[i];
+
+    delete[] Vtemp;
 }
 
 
