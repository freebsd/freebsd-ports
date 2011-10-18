--- src/ApvlvFile.cpp.orig	2011-06-24 11:30:12.000000000 +0400
+++ src/ApvlvFile.cpp	2011-10-10 01:01:26.000000000 +0400
@@ -302,9 +302,9 @@
 
 bool ApvlvPDF::pagetext (int pn, int x1, int y1, int x2, int y2, char **out)
 {
-  PopplerRectangle rect = { x1, y1, x2, y2 };
   PopplerPage *page = poppler_document_get_page (mDoc, pn);
-  *out = poppler_page_get_text (page, POPPLER_SELECTION_WORD, &rect);
+  PopplerRectangle rect = { x1, y2, x2, y1 };
+  *out = poppler_page_get_selected_text (page, POPPLER_SELECTION_WORD, &rect);
   if (*out != NULL)
     {
       return true;
