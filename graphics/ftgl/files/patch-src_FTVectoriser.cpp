--- src/FTVectoriser.cpp.orig	2019-02-07 21:39:58 UTC
+++ src/FTVectoriser.cpp
@@ -168,7 +168,7 @@ void FTVectoriser::ProcessContours()
     for(int i = 0; i < ftContourCount; ++i)
     {
         FT_Vector* pointList = &outline.points[startIndex];
-        char* tagList = &outline.tags[startIndex];
+        unsigned char* tagList = &outline.tags[startIndex];
 
         endIndex = outline.contours[i];
         contourLength =  (endIndex - startIndex) + 1;
