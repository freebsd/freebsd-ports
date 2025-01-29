--- src/geo/GFace.h.orig	2024-03-29 22:07:00 UTC
+++ src/geo/GFace.h
@@ -10,13 +10,13 @@
 #include <string>
 #include <vector>
 #include <map>
+#include <utility>
 #include "GmshDefines.h"
 #include "GEntity.h"
 #include "GPoint.h"
 #include "GEdgeLoop.h"
 #include "SPoint2.h"
 #include "SVector3.h"
-#include "Pair.h"
 #include "Numeric.h"
 #include "boundaryLayersData.h"
 
@@ -201,7 +201,7 @@ class GFace : public GEntity { (public)
   virtual SVector3 normal(const SPoint2 &param) const;
 
   // return the first derivate of the face at the parameter location
-  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const = 0;
+  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param) const = 0;
 
   // compute the second derivates of the face at the parameter location
   virtual void secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
