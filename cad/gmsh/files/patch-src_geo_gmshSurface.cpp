--- src/geo/gmshSurface.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/geo/gmshSurface.cpp
@@ -23,10 +23,10 @@ SVector3 gmshSurface::normal(const SPoint2 &param) con
   return SVector3();
 }
 
-Pair<SVector3, SVector3> gmshSurface::firstDer(const SPoint2 &param)
+std::pair<SVector3, SVector3> gmshSurface::firstDer(const SPoint2 &param)
 {
   Msg::Error("First derivative not implemented for this type of surface");
-  return Pair<SVector3, SVector3>();
+  return std::pair<SVector3, SVector3>();
 }
 
 double gmshSurface::getMetricEigenvalue(const SPoint2 &)
