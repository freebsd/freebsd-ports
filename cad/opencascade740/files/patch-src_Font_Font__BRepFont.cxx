--- src/Font/Font_BRepFont.cxx.orig	2024-09-24 18:34:32 UTC
+++ src/Font/Font_BRepFont.cxx
@@ -430,7 +430,7 @@ Standard_Boolean Font_BRepFont::renderGlyph (const Sta
   for (short aContour = 0, aStartIndex = 0; aContour < anOutline.n_contours; ++aContour)
   {
     const FT_Vector* aPntList = &anOutline.points[aStartIndex];
-    const char* aTags      = &anOutline.tags[aStartIndex];
+    const auto* aTags      = &anOutline.tags[aStartIndex];
     const short anEndIndex = anOutline.contours[aContour];
     const short aPntsNb    = (anEndIndex - aStartIndex) + 1;
     aStartIndex = anEndIndex + 1;
