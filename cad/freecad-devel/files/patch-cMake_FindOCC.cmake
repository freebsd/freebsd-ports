--- cMake/FindOCC.cmake.orig	2025-07-21 02:26:03 UTC
+++ cMake/FindOCC.cmake
@@ -109,6 +109,7 @@ if (OCC_FOUND)
             TKPrim
             TKHLR
             TKFeat
+            TKExpress
     )
     if (OCC_VERSION_STRING VERSION_GREATER_EQUAL 7.9.0)
         list(APPEND OCC_LIBRARIES TKExpress)
