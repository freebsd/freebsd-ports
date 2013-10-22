--- ./modules/contrib/src/spinimages.cpp.orig	2013-10-22 07:55:31.000000000 -0400
+++ ./modules/contrib/src/spinimages.cpp	2013-10-22 07:55:51.000000000 -0400
@@ -85,7 +85,7 @@
     };
     size_t colors_mum = sizeof(colors)/sizeof(colors[0]);
 
-template<class FwIt, class T> void iota(FwIt first, FwIt last, T value) { while(first != last) *first++ = value++; }
+template<class FwIt, class T> void _iota(FwIt first, FwIt last, T value) { while(first != last) *first++ = value++; }
 
 void computeNormals( const Octree& Octree, const vector<Point3f>& centers, vector<Point3f>& normals, 
                     vector<uchar>& mask, float normalRadius, int minNeighbors = 20)
@@ -790,14 +790,14 @@
     else if (setSize == vtxSize)
     {
         subset.resize(vtxSize);
-        iota(subset.begin(), subset.end(), 0);
+        _iota(subset.begin(), subset.end(), 0);
     }
     else
     {
         RNG& rnd = theRNG();
 
         vector<size_t> left(vtxSize);
-        iota(left.begin(), left.end(), (size_t)0);
+        _iota(left.begin(), left.end(), (size_t)0);
 
         subset.resize(setSize);
         for(size_t i = 0; i < setSize; ++i)
@@ -870,7 +870,7 @@
     {
         mesh.computeNormals(normalRadius, minNeighbors);
         subset.resize(mesh.vtx.size());
-        iota(subset.begin(), subset.end(), 0);
+        _iota(subset.begin(), subset.end(), 0);
     }
     else
         mesh.computeNormals(subset, normalRadius, minNeighbors);
