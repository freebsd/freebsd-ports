--- src/geo/OCCFace.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/geo/OCCFace.cpp
@@ -249,13 +249,13 @@ SVector3 OCCFace::normal(const SPoint2 &param) const
   return n;
 }
 
-Pair<SVector3, SVector3> OCCFace::firstDer(const SPoint2 &param) const
+std::pair<SVector3, SVector3> OCCFace::firstDer(const SPoint2 &param) const
 {
   gp_Pnt pnt;
   gp_Vec du, dv;
   _occface->D1(param.x(), param.y(), pnt, du, dv);
-  return Pair<SVector3, SVector3>(SVector3(du.X(), du.Y(), du.Z()),
-                                  SVector3(dv.X(), dv.Y(), dv.Z()));
+  return std::make_pair(SVector3(du.X(), du.Y(), du.Z()),
+                        SVector3(dv.X(), dv.Y(), dv.Z()));
 }
 
 void OCCFace::secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
