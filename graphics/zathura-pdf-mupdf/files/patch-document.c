--- document.c.orig	2016-02-14 22:49:46 UTC
+++ document.c
@@ -113,8 +113,8 @@ pdf_document_save_as(zathura_document_t*
      * pdf_write_document does not check if the third arguments is NULL for some
      * options. */
 
-    fz_write_options opts = { 0 }; /* just use the default options */
-    fz_write_document(mupdf_document->ctx, mupdf_document->document, (char*) path, &opts);
+    pdf_write_options opts = { 0 }; /* just use the default options */
+    pdf_save_document(mupdf_document->ctx, mupdf_document->document, (char*) path, &opts);
   } fz_catch (mupdf_document->ctx) {
     return ZATHURA_ERROR_UNKNOWN;
   }
