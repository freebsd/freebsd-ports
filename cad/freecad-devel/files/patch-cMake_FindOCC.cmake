--- cMake/FindOCC.cmake.orig	2026-08-18 05:35:46 UTC
+++ cMake/FindOCC.cmake
@@ -118,6 +118,7 @@ if (OCC_FOUND)
             TKPrim
             TKHLR
             TKFeat
+            TKExpress
     )
     if (OCC_VERSION_STRING VERSION_GREATER_EQUAL 7.9.0)
         list(APPEND OCC_LIBRARIES TKExpress)
