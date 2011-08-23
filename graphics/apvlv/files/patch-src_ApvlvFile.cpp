--- src/ApvlvFile.cpp.orig	2011-08-12 10:22:23.000000000 +0200
+++ src/ApvlvFile.cpp	2011-08-12 10:24:26.000000000 +0200
@@ -273,9 +273,9 @@ ApvlvPDF::ApvlvPDF (const char *filename
 
   bool ApvlvPDF::pagetext (int pn, int x1, int y1, int x2, int y2, char **out)
   {
-    PopplerRectangle rect = { x1, y1, x2, y2 };
     PopplerPage *page = poppler_document_get_page (mDoc, pn);
-    *out = poppler_page_get_text (page, POPPLER_SELECTION_WORD, &rect);
+    PopplerRectangle rect = { x1, y2, x2, y1 };
+    *out = poppler_page_get_selected_text (page, POPPLER_SELECTION_WORD, &rect);
     if (*out != NULL)
       {
 	return true;
