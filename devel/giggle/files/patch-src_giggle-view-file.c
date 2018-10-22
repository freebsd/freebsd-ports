--- src/giggle-view-file.c.orig	2012-11-01 05:29:01 UTC
+++ src/giggle-view-file.c
@@ -38,8 +38,7 @@
 #include <gio/gio.h>
 #include <glib/gi18n.h>
 
-#include <gtksourceview/gtksourcelanguagemanager.h>
-#include <gtksourceview/gtksourceview.h>
+#include <gtksourceview/gtksource.h>
 
 #define GIGGLE_TYPE_VIEW_FILE_SNAPSHOT            (giggle_view_file_snapshot_get_type ())
 #define GIGGLE_VIEW_FILE_SNAPSHOT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_VIEW_FILE_SNAPSHOT, GiggleViewFileSnapshot))
