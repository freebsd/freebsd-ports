--- src/StdPrs/StdPrs_BRepFont.cxx.orig	2024-03-31 22:05:22 UTC
+++ src/StdPrs/StdPrs_BRepFont.cxx
@@ -457,7 +457,7 @@ Standard_Boolean StdPrs_BRepFont::renderGlyph (const S
   for (short aContour = 0, aStartIndex = 0; aContour < anOutline->n_contours; ++aContour)
   {
     const FT_Vector* aPntList = &anOutline->points[aStartIndex];
-    const char* aTags      = &anOutline->tags[aStartIndex];
+    const auto* aTags      = &anOutline->tags[aStartIndex];
     const short anEndIndex = anOutline->contours[aContour];
     const short aPntsNb    = (anEndIndex - aStartIndex) + 1;
     aStartIndex = anEndIndex + 1;
