--- dialog.c.orig	Thu Apr 15 17:05:14 1999
+++ dialog.c	Thu Feb  2 16:40:36 2006
@@ -112,10 +112,15 @@
   gtk_widget_set_usize (fixed_top, 353, 225);
 
   sprintf (pixmap_path, "%s/xpm/iglooftp.xpm", SHARE_PATH);
-  pixmap = gdk_pixmap_create_from_xpm (startup_window->window, &mask, &startup_window->style->bg[GTK_STATE_NORMAL], pixmap_path);
-  igloo_pixmap = gtk_pixmap_new (pixmap, mask);
 
-  gtk_fixed_put (GTK_FIXED (fixed_top), igloo_pixmap, 0, 0);
+  if (eaccess(pixmap_path, R_OK) == 0) {
+      pixmap = gdk_pixmap_create_from_xpm (startup_window->window, &mask, &startup_window->style->bg[GTK_STATE_NORMAL], pixmap_path);
+      igloo_pixmap = gtk_pixmap_new (pixmap, mask);
+
+      gtk_fixed_put (GTK_FIXED (fixed_top), igloo_pixmap, 0, 0);
+  } else {
+      mask = pixmap = NULL;
+  }
 
   startup_label = fixed_label (fixed_top, 10, 205, " ");
   gtk_widget_set_usize (startup_label, 300, 24);
@@ -126,8 +131,8 @@
   gtk_widget_show_all (startup_window);
 
   PROCESS_EVENTS;
-  gdk_pixmap_unref (pixmap);
-  gdk_pixmap_unref (mask);
+  if (pixmap) gdk_pixmap_unref (pixmap);
+  if (mask) gdk_pixmap_unref (mask);
 }
 
 
@@ -173,14 +178,22 @@
   alert_hbox = h_box (alert_vbox, FALSE, 0, 0);
 
   sprintf (pixmap_path, "%s/xpm/little_igloo.xpm", SHARE_PATH);
-  pixmap = gdk_pixmap_create_from_xpm (alert_window->window, &mask, &alert_window->style->bg[GTK_STATE_NORMAL], pixmap_path);
-  igloo_pixmap = gtk_pixmap_new (pixmap, mask);
+
+  if (eaccess(pixmap_path, R_OK) == 0) {
+      pixmap = gdk_pixmap_create_from_xpm (alert_window->window, &mask, &alert_window->style->bg[GTK_STATE_NORMAL], pixmap_path);
+      igloo_pixmap = gtk_pixmap_new (pixmap, mask);
+  } else {
+      pixmap = mask = NULL;
+  }
 
   alert_button = gtk_button_new ();
   gtk_button_set_relief (GTK_BUTTON (alert_button), GTK_RELIEF_NONE);
 
-  gtk_container_add (GTK_CONTAINER (alert_button), igloo_pixmap);
-  gtk_widget_show (igloo_pixmap);
+  if (pixmap) {
+      gtk_container_add (GTK_CONTAINER (alert_button), igloo_pixmap);
+      gtk_widget_show (igloo_pixmap);
+  }
+
   gtk_box_pack_start (GTK_BOX (alert_hbox), alert_button, TRUE, TRUE, 0);
   gtk_widget_show (alert_button);
   gtk_signal_connect (GTK_OBJECT (alert_button), "clicked", GTK_SIGNAL_FUNC (open_URL_from_widget), strdup (HOME_URL));
@@ -198,8 +211,8 @@
 
   gtk_widget_show (alert_window);
 
-  gdk_pixmap_unref (pixmap);
-  gdk_pixmap_unref (mask);
+  if (pixmap) gdk_pixmap_unref (pixmap);
+  if (mask) gdk_pixmap_unref (mask);
 }
 
 
