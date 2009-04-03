--- src/liborsa/orsa_body.h.orig	2004-12-30 12:58:03.000000000 +0900
+++ src/liborsa/orsa_body.h	2009-04-02 13:48:37.000000000 +0900
@@ -183,7 +183,7 @@
     inline void SetVelocity(const double x, const double y, const double z) { Vector v(x,y,z); SetVelocity(v); }
     
     // b position - this position
-    inline Vector Body::distanceVector(const Body & b) const { return b.position()-position(); }
+    inline Vector distanceVector(const Body & b) const { return b.position()-position(); }
     inline double distance(const Body & b) const { return distanceVector(b).Length(); }
     
     // alias
