--- src/geo/gmshFace.h.orig	2024-03-29 22:07:01 UTC
+++ src/geo/gmshFace.h
@@ -26,7 +26,7 @@ class gmshFace : public GFace { (public)
   virtual bool containsPoint(const SPoint3 &pt) const;
   virtual double getMetricEigenvalue(const SPoint2 &);
   virtual SVector3 normal(const SPoint2 &param) const;
-  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
+  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
   virtual void secondDer(const SPoint2 &, SVector3 &, SVector3 &,
                          SVector3 &) const;
   virtual GEntity::GeomType geomType() const;
