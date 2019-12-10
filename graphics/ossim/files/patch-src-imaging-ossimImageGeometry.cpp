Obtained from:	https://github.com/ossimlabs/ossim/commit/c456397821cf369af4d9ff1fb60a5dfd1bcefc24

--- src/imaging/ossimImageGeometry.cpp.orig	2019-10-17 21:54:21 UTC
+++ src/imaging/ossimImageGeometry.cpp
@@ -1240,7 +1240,7 @@ void ossimImageGeometry::calculatePolyBo
       }
       result.add(ossimPolygon(gPoints));
    }
-   if(!result.isValid()) result.setToBufferedShape();
+   if(!result.isValid()) result.makeValid();
 }
 
 
