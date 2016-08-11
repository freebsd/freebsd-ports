--- src/main.cc.orig	2003-05-07 15:06:31 UTC
+++ src/main.cc
@@ -18,7 +18,7 @@ int main (int argc, char *argv[]) {
    gtk_set_locale ();
    gtk_init (&argc, &argv);
 
-   add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps/graphopt");
+   add_pixmap_directory (PACKAGE_DATA_DIR "/graphopt/pixmaps");
    add_pixmap_directory (PACKAGE_SOURCE_DIR "/pixmaps");
 
    window1 = create_window1();
