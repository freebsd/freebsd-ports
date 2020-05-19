--- zathura-pdf-mupdf/index.c.orig	2020-05-18 10:56:42 UTC
+++ zathura-pdf-mupdf/index.c
@@ -67,7 +67,7 @@ build_index(fz_context* ctx, fz_document* document, fz
 
       type                    = ZATHURA_LINK_GOTO_DEST;
       target.destination_type = ZATHURA_LINK_DESTINATION_XYZ;
-      target.page_number      = fz_resolve_link(ctx, document, outline->uri, &x, &y);
+      target.page_number      = fz_page_number_from_location(ctx, document, fz_resolve_link(ctx, document, outline->uri, &x, &y));
       target.left  = x;
       target.top   = y;
       target.zoom  = 0.0;
