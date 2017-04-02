--- src/gui/dialogs/about.cpp.orig	2017-04-02 22:45:26 UTC
+++ src/gui/dialogs/about.cpp
@@ -204,7 +204,7 @@ About::About()
 	imagepath+=ETL_DIRECTORY_SEPARATOR;
 
 	Gtk::Image *Logo = manage(new class Gtk::Image());
-	Logo->set(imagepath+"synfig_icon."IMAGE_EXT);
+	Logo->set(imagepath+"synfig_icon." IMAGE_EXT);
 	set_logo(Logo->get_pixbuf());
 
 #ifdef SHOW_EXTRA_INFO
