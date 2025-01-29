--- src/geo/gmshFace.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/geo/gmshFace.cpp
@@ -215,19 +215,19 @@ SVector3 gmshFace::normal(const SPoint2 &param) const
   }
 }
 
-Pair<SVector3, SVector3> gmshFace::firstDer(const SPoint2 &param) const
+std::pair<SVector3, SVector3> gmshFace::firstDer(const SPoint2 &param) const
 {
   if(_s->Typ == MSH_SURF_PLAN && !_s->geometry) {
     double x, y, z, VX[3], VY[3];
     getMeanPlaneData(VX, VY, x, y, z);
-    return Pair<SVector3, SVector3>(SVector3(VX[0], VX[1], VX[2]),
-                                    SVector3(VY[0], VY[1], VY[2]));
+    return std::make_pair(SVector3(VX[0], VX[1], VX[2]),
+                          SVector3(VY[0], VY[1], VY[2]));
   }
   else {
     Vertex vu = InterpolateSurface(_s, param[0], param[1], 1, 1);
     Vertex vv = InterpolateSurface(_s, param[0], param[1], 1, 2);
-    return Pair<SVector3, SVector3>(SVector3(vu.Pos.X, vu.Pos.Y, vu.Pos.Z),
-                                    SVector3(vv.Pos.X, vv.Pos.Y, vv.Pos.Z));
+    return std::make_pair(SVector3(vu.Pos.X, vu.Pos.Y, vu.Pos.Z),
+                          SVector3(vv.Pos.X, vv.Pos.Y, vv.Pos.Z));
   }
 }
 
