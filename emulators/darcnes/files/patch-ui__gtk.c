--- ui_gtk.c.orig	2000-08-22 02:06:48 UTC
+++ ui_gtk.c
@@ -63,6 +63,7 @@ int main( int argc, char* argv[] )
   video_buffer_1 = video_buffer_2 = NULL;
 
   /* Get Gtk up and running. */
+  gtk_set_locale();
   gtk_init( &argc, &argv );
 
   nes_gtk_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
