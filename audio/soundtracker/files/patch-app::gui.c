--- app/gui.c.orig	Sun Jan 11 22:46:26 2004
+++ app/gui.c	Thu Jan 29 19:29:45 2004
@@ -1724,7 +1724,7 @@
     /* Show splash screen if enabled and image available. */
 
 #ifndef NO_GDK_PIXBUF
-    gui_splash_logo = gdk_pixbuf_new_from_file(PREFIX"/share/soundtracker/soundtracker_splash.png");
+    gui_splash_logo = gdk_pixbuf_new_from_file(DATADIR"/soundtracker_splash.png");
     if(gui_splash_logo) {
 	thing = gtk_hseparator_new();
 	gtk_widget_show(thing);
@@ -1925,7 +1925,7 @@
 
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/play.xpm");
+	DATADIR"/play.xpm");
     pmw = gtk_pixmap_new(pm, mask);
     pbutton = thing = gtk_button_new();
     gtk_container_add(GTK_CONTAINER(thing), pmw);
@@ -1937,7 +1937,7 @@
 
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/play_cur.xpm");
+	DATADIR"/play_cur.xpm");
     pmw = gtk_pixmap_new(pm, mask);
     thing = gtk_button_new();
     gtk_container_add(GTK_CONTAINER(thing), pmw);
@@ -1949,7 +1949,7 @@
 
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/stop.xpm");
+	DATADIR"/stop.xpm");
     pmw = gtk_pixmap_new(pm, mask);
     thing = gtk_button_new();
     gtk_container_add(GTK_CONTAINER(thing), pmw);
@@ -1975,7 +1975,7 @@
 		       
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/lock.xpm");
+	DATADIR"/lock.xpm");
     pmw = gtk_pixmap_new(pm, mask);
     toggle_lock_editpat = thing = gtk_toggle_button_new();
     gtk_container_add(GTK_CONTAINER(thing), pmw);
@@ -2033,13 +2033,13 @@
     vbox = gtk_vbox_new(FALSE, 0);
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/sharp.xpm");
+	DATADIR"/sharp.xpm");
     alt[0] = gtk_pixmap_new(pm, mask);
     gtk_box_pack_start(GTK_BOX(vbox), alt[0], FALSE, FALSE, 0);
     
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/flat.xpm");
+	DATADIR"/flat.xpm");
     alt[1] = gtk_pixmap_new(pm, mask);
     gtk_widget_show(alt[gui_settings.sharp ? 0 : 1]);
     gtk_box_pack_start(GTK_BOX(vbox), alt[1], FALSE, FALSE, 0);
@@ -2102,13 +2102,13 @@
     vbox = gtk_vbox_new(FALSE, 0);
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/downarrow.xpm");
+	DATADIR"/downarrow.xpm");
     arrow[0] = gtk_pixmap_new(pm, mask);
     gtk_box_pack_start(GTK_BOX(vbox), arrow[0], FALSE, FALSE, 0);
     
     pm = gdk_pixmap_create_from_xpm(mainwindow->window,
 	&mask, &style->bg[GTK_STATE_NORMAL],
-	PREFIX"/share/soundtracker/rightarrow.xpm");
+	DATADIR"/rightarrow.xpm");
     arrow[1] = gtk_pixmap_new(pm, mask);
     gtk_box_pack_start(GTK_BOX(vbox), arrow[1], FALSE, FALSE, 0);
     gtk_widget_show(arrow[gui_settings.advance_cursor_in_fx_columns ? 1 : 0]);
@@ -2129,7 +2129,7 @@
     gtk_widget_show(thing);
 
 #ifndef NO_GDK_PIXBUF
-    scopegroup = SCOPE_GROUP(scope_group_new(gdk_pixbuf_new_from_file(PREFIX"/share/soundtracker/muted.png")));
+    scopegroup = SCOPE_GROUP(scope_group_new(gdk_pixbuf_new_from_file(DATADIR"/muted.png")));
 #else
     scopegroup = SCOPE_GROUP(scope_group_new());
 #endif
