--- src/FTContour.h.orig	2019-02-07 21:39:58 UTC
+++ src/FTContour.h
@@ -52,7 +52,7 @@ class FTContour
          * @param pointTags
          * @param numberOfPoints
          */
-        FTContour(FT_Vector* contour, char* pointTags, unsigned int numberOfPoints);
+        FTContour(FT_Vector* contour, unsigned char* pointTags, unsigned int numberOfPoints);
 
         /**
          * Destructor
