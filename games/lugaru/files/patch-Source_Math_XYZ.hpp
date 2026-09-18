--- Source/Math/XYZ.hpp.orig	2026-09-18 15:42:30 UTC
+++ Source/Math/XYZ.hpp
@@ -55,7 +55,7 @@ inline float normaldotproduct(XYZ point1, XYZ point2);
 inline void CrossProduct(XYZ P, XYZ Q, XYZ* V);
 inline void Normalise(XYZ* vectory);
 inline float normaldotproduct(XYZ point1, XYZ point2);
-inline float fast_sqrt(register float arg);
+inline float fast_sqrt(float arg);
 bool PointInTriangle(XYZ* p, XYZ normal, XYZ* p1, XYZ* p2, XYZ* p3);
 bool LineFacet(XYZ p1, XYZ p2, XYZ pa, XYZ pb, XYZ pc, XYZ* p);
 float LineFacetd(XYZ p1, XYZ p2, XYZ pa, XYZ pb, XYZ pc, XYZ* p);
@@ -203,7 +203,7 @@ inline void CrossProduct(XYZ P, XYZ Q, XYZ* V)
     V->z = P.x * Q.y - P.y * Q.x;
 }
 
-inline float fast_sqrt(register float arg)
+inline float fast_sqrt(float arg)
 {
     return sqrtf(arg);
 }
