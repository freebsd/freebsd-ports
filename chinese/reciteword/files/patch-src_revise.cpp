--- src/revise.cpp.orig	2006-03-26 16:33:14.000000000 +0800
+++ src/revise.cpp	2007-07-30 16:38:45.000000000 +0800
@@ -240,7 +240,7 @@
 static void
 on_revise_group_plane_clicked (gpointer data)
 {
-	gint index = (gint) data;
+	glong index = (glong) data;
 	gint zu_index = g_pReciteWord->revise_group->revise_zu_index[index];
 
 	gint i, tmpint, last_zu_wordcount = 25, now_wordcount = 0;
@@ -326,7 +326,7 @@
 			     "revise_group", "disorder",
 			     &order);
 	order_ckbutton.set_status(order);
-	gint found_group = 0;
+	glong found_group = 0;
 	gint found = TRUE;
 	gint zu_index = 0, revise_times;
 	gchar tmpstr[256];
@@ -370,7 +370,7 @@
 		if (zu_index > g_pReciteWord->max_zu_index)	//the current book is search over....will try old books.
 			found = FALSE;
 	}
-	sprintf(tmpstr,_("found %d groups in total"),found_group);
+	sprintf(tmpstr,_("found %ld groups in total"),found_group);
 	total_groups_label = gtk_label_new(tmpstr);
 	gtk_fixed_put (GTK_FIXED (g_pReciteWord->fixed), total_groups_label,
 		       Skin->revise_group.total_groups_label.x[0], Skin->revise_group.total_groups_label.y[0]);
@@ -378,7 +378,7 @@
 }
 
 void
-CRevise_group::create_plane (gint x, gint y)
+CRevise_group::create_plane (glong x, glong y)
 {
 	gchar tmpstr[246];
 	sprintf(tmpstr,_("G%d"),revise_zu_index[y]+1);
@@ -396,7 +396,7 @@
 				 Skin->revise_group.plane_button_p.p[1],
 				 tmpstr,
 				 on_revise_group_plane_clicked,
-				 GINT_TO_POINTER (y));
+				 (gpointer)y);
 	plane[y] = new tPixButton;
 	plane[y]->create (g_pReciteWord->fixed,
 			  Skin->revise_group.plane[x][y].x[0],
@@ -404,7 +404,7 @@
 			  Skin->revise_group.plane[x][y].p[0],
 			  Skin->revise_group.plane[x][y].p[1],
 			  (GdkPixmap *) NULL, on_revise_group_plane_clicked,
-			  GINT_TO_POINTER (y));
+			  (gpointer)y);
 	const gchar tooltips[5][3]={"F1","F2","F3","F4","F5"};
 	gtk_tooltips_set_tip (g_pReciteWord->tooltips, plane[y]->event_box,tooltips[y],"");
 	if (Skin->revise_group.plane_h[x][y].w)
@@ -588,7 +588,6 @@
 	gdk_colormap_alloc_color (parent->cmap, &(parent->color), FALSE,
 				  TRUE);
 	//gdk_color_change(parent->cmap,&(parent->color));
-	parent->draw (3);
 	if (parent->color.red == 0x0000)
 	{
 		parent->refresh();
@@ -610,8 +609,10 @@
 		parent->disappear_timer = 0;
 		return FALSE;
 	}
-	else
+	else {
+		parent->draw (3);
 		return TRUE;
+	}
 }
 
 tViewer::tViewer ()
@@ -676,13 +677,17 @@
 	str2 = str_m;
 	if (layout_w)
 		pango_layout_set_text(layout_w,str1,-1);
-	else
-	{
+	else {
 		layout_w=gtk_widget_create_pango_layout (text_area, str1);
 		pango_layout_set_font_description(layout_w,Skin->reciteword.b_font);
 	}
-	if (layout_m)
-		pango_layout_set_text(layout_m,str2,-1);
+	if (layout_m) {
+		if (str2) {
+			pango_layout_set_text(layout_m,str2,-1);
+		} else {
+			pango_layout_set_text(layout_m,"",-1);
+		}
+	}
 	else
 		layout_m=gtk_widget_create_pango_layout (text_area, str2);
 	if (g_pReciteWord->revise_skim->readword_ckbutton.status)
