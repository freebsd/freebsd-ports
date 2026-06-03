--- thirdparty/ftgl/FTVectoriser.cpp.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/ftgl/FTVectoriser.cpp
@@ -130,7 +130,7 @@ void FTVectoriser::ProcessContours()
 #if FREETYPE_MAJOR==2 && FREETYPE_MINOR == 13 && FREETYPE_PATCH >= 3
       unsigned
 #endif
-      char* tagList = &outline.tags[startIndex];
+      char* tagList = reinterpret_cast<char*>(&outline.tags[startIndex]);
 
       endIndex = outline.contours[i];
       contourLength =  (endIndex - startIndex) + 1;
