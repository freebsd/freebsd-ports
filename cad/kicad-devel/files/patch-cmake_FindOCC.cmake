--- cmake/FindOCC.cmake.orig	2023-06-22 13:35:48 UTC
+++ cmake/FindOCC.cmake
@@ -45,7 +45,7 @@ set( OCC_LIBS
     TKGeomAlgo
     TKGeomBase
     TKHLR
-    TKIGES
+    TKDEIGES
     TKLCAF
     TKMath
     TKMesh
@@ -55,18 +55,15 @@ set( OCC_LIBS
     TKPrim
     TKService
     TKShHealing
-    TKSTEP209
-    TKSTEPAttr
-    TKSTEPBase
-    TKSTEP
-    TKSTL
+    TKDESTEP
+    TKDESTL
     TKTObj
     TKTopAlgo
     TKV3d
-    TKVRML
+    TKDEVRML
     TKXCAF
-    TKXDEIGES
-    TKXDESTEP
+    TKXSDRAWIGES
+    TKXSDRAWSTEP
     TKXMesh
     TKXmlL
     TKXml
