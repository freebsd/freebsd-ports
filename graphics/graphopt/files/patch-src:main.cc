--- src/main.cc.orig	Fri Dec  5 22:57:02 2003
+++ src/main.cc	Fri Dec  5 22:57:20 2003
@@ -18,7 +18,7 @@
    gtk_set_locale ();
    gtk_init (&argc, &argv);
 
-   add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps/graphopt");
+   add_pixmap_directory (PACKAGE_DATA_DIR "/graphopt/pixmaps");
    add_pixmap_directory (PACKAGE_SOURCE_DIR "/pixmaps");
 
    window1 = create_window1();
