--- zathura-pdf-mupdf/links.c.orig	2020-05-18 11:05:39 UTC
+++ zathura-pdf-mupdf/links.c
@@ -56,8 +56,10 @@ pdf_page_links_get(zathura_page_t* page, void* data, z
 
       type                    = ZATHURA_LINK_GOTO_DEST;
       target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-      target.page_number      = fz_resolve_link(mupdf_document->ctx,
-          mupdf_document->document, link->uri, &x, &y);
+      target.page_number      =
+	      fz_page_number_from_location(mupdf_document->ctx,
+			      mupdf_document->document, fz_resolve_link(mupdf_document->ctx,
+          mupdf_document->document, link->uri, &x, &y));
       target.left  = x;
       target.top   = y;
       target.zoom  = 0.0;
