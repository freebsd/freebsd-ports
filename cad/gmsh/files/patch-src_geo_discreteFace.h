--- src/geo/discreteFace.h.orig	2024-04-18 14:52:42 UTC
+++ src/geo/discreteFace.h
@@ -60,7 +60,7 @@ class discreteFace : public GFace { (public)
   double curvatures(const SPoint2 &param, SVector3 &dirMax, SVector3 &dirMin,
                     double &curvMax, double &curvMin) const;
   GEntity::GeomType geomType() const { return DiscreteSurface; }
-  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
+  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
   virtual void secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                          SVector3 &dudv) const;
   int createGeometry();
