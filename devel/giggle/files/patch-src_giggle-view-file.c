--- src/giggle-view-file.c.orig	2012-11-01 06:29:01.000000000 +0100
+++ src/giggle-view-file.c	2014-10-01 23:37:28.646714997 +0200
@@ -39,6 +39,7 @@
 #include <glib/gi18n.h>
 
 #include <gtksourceview/gtksourcelanguagemanager.h>
+#include <gtksourceview/gtksourcebuffer.h>
 #include <gtksourceview/gtksourceview.h>
 
 #define GIGGLE_TYPE_VIEW_FILE_SNAPSHOT            (giggle_view_file_snapshot_get_type ())
