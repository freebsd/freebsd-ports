--- src/geo/xyFace.h.orig	2024-03-29 22:07:01 UTC
+++ src/geo/xyFace.h
@@ -33,11 +33,11 @@ class xyFace : public GFace { (public)
     SVector3 n(0, 0, 1);
     return n;
   }
-  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const
+  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param) const
   {
     SVector3 t1(1, 0, 0);
     SVector3 t2(0, 1, 0);
-    return Pair<SVector3, SVector3>(t1, t2);
+    return std::make_pair(t1, t2);
   }
   virtual void secondDer(const SPoint2 &, SVector3 &a, SVector3 &b,
                          SVector3 &c) const
