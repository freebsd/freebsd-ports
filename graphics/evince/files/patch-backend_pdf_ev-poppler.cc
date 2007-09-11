--- backend/pdf/ev-poppler.cc.orig	2007-09-11 02:17:19.000000000 -0400
+++ backend/pdf/ev-poppler.cc	2007-09-11 02:22:10.000000000 -0400
@@ -654,7 +654,7 @@ pdf_document_get_text (EvDocument *docum
 	r.x2 = rect->x2;
 	r.y2 = height - rect->y1;
 
-	text = poppler_page_get_text (poppler_page, &r);
+	text = poppler_page_get_text (poppler_page, POPPLER_SELECTION_GLYPH, &r);
 
 	g_object_unref (poppler_page);
 
@@ -1636,7 +1636,7 @@ pdf_selection_render_selection (EvSelect
 						 rc->scale, rc->rotation, *pixbuf,
 						 (PopplerRectangle *)points,
 						 (PopplerRectangle *)old_points,
-						 POPPLER_SELECTION_NORMAL,
+						 POPPLER_SELECTION_GLYPH,
 						 text,
 						 base);
 #endif
@@ -1655,7 +1655,7 @@ pdf_selection_get_selection_region (EvSe
 
 	set_rc_data (pdf_document, rc);
 
-	retval = poppler_page_get_selection_region ((PopplerPage *)rc->data, rc->scale, (PopplerRectangle *) points);
+	retval = poppler_page_get_selection_region ((PopplerPage *)rc->data, rc->scale, POPPLER_SELECTION_GLYPH, (PopplerRectangle *) points);
 
 	return retval;
 }
@@ -1676,7 +1676,7 @@ pdf_selection_get_selection_map (EvSelec
 	points.x1 = 0.0;
 	points.y1 = 0.0;
 	poppler_page_get_size (poppler_page, &(points.x2), &(points.y2));
-	retval = poppler_page_get_selection_region (poppler_page, 1.0, &points);
+	retval = poppler_page_get_selection_region (poppler_page, 1.0, POPPLER_SELECTION_GLYPH, &points);
 	g_object_unref (poppler_page);
 
 	return retval;
