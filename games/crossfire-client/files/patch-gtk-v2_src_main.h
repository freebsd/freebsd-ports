--- gtk-v2/src/main.h.orig	2020-08-28 18:06:06 UTC
+++ gtk-v2/src/main.h
@@ -34,7 +34,7 @@ extern int map_image_size, map_image_half_size, image_
 #define DIALOG_FILENAME CF_DATADIR "/ui/dialogs.ui"
 
 /** Path to the current UI file. */
-char window_xml_file[MAX_BUF];
+extern char window_xml_file[MAX_BUF];
 
 #define MAGIC_MAP_PAGE  1 /**< Notebook page of the magic map */
 
