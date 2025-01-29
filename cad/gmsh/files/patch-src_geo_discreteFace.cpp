--- src/geo/discreteFace.cpp.orig	2024-04-18 14:52:42 UTC
+++ src/geo/discreteFace.cpp
@@ -363,16 +363,16 @@ double discreteFace::curvatures(const SPoint2 &param, 
   return false;
 }
 
-Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
+std::pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
 {
-  if(_param.empty()) return Pair<SVector3, SVector3>(SVector3(), SVector3());
+  if(_param.empty()) return std::make_pair(SVector3(), SVector3());
 
   MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
   if(!e) {
     Msg::Info("Triangle not found for first derivative at uv=(%g,%g) on "
               "discrete surface %d",
               param.x(), param.y(), tag());
-    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));
+    return std::make_pair(SVector3(1, 0, 0), SVector3(0, 1, 0));
   }
 
   int position = (int)((MTriangle *)e - &_param.t2d[0]);
@@ -403,8 +403,8 @@ Pair<SVector3, SVector3> discreteFace::firstDer(const 
     }
   }
 
-  return Pair<SVector3, SVector3>(SVector3(dxdu[0][0], dxdu[1][0], dxdu[2][0]),
-                                  SVector3(dxdu[0][1], dxdu[1][1], dxdu[2][1]));
+  return std::make_pair(SVector3(dxdu[0][0], dxdu[1][0], dxdu[2][0]),
+                        SVector3(dxdu[0][1], dxdu[1][1], dxdu[2][1]));
 }
 
 void discreteFace::secondDer(const SPoint2 &param, SVector3 &dudu,
