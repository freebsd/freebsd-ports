--- ui_gtk.c.orig	Tue Aug 22 11:06:48 2000
+++ ui_gtk.c	Mon Feb  2 20:12:54 2004
@@ -63,6 +63,7 @@
   video_buffer_1 = video_buffer_2 = NULL;
 
   /* Get Gtk up and running. */
+  gtk_set_locale();
   gtk_init( &argc, &argv );
 
   nes_gtk_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
