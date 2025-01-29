--- src/geo/gmshSurface.h.orig	2024-03-29 22:07:01 UTC
+++ src/geo/gmshSurface.h
@@ -9,7 +9,6 @@
 #include <cmath>
 #include <cstdio>
 #include <map>
-#include "Pair.h"
 #include "Range.h"
 #include "SPoint2.h"
 #include "SPoint3.h"
@@ -61,7 +60,7 @@ class gmshSurface { (public)
   // Return the normal to the face at the given parameter location.
   virtual SVector3 normal(const SPoint2 &param) const;
   // Return the first derivate of the face at the parameter location.
-  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param);
+  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param);
   virtual double getMetricEigenvalue(const SPoint2 &);
 };
 
