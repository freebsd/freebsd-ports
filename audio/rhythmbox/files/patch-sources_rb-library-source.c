--- sources/rb-library-source.c.orig	Thu Oct 23 22:18:14 2003
+++ sources/rb-library-source.c	Thu Oct 23 22:18:24 2003
@@ -1358,9 +1358,9 @@
 static void
 query_complete_cb (RhythmDBQueryModel *model, RBLibrarySource *source)
 {
-	rb_debug ("query complete");
 	struct RBLibrarySourceQueryCompleteData *data
 		= g_new0 (struct RBLibrarySourceQueryCompleteData, 1);
+	rb_debug ("query complete");
 	data->model = model;
 	data->source = source;
 	g_object_ref (G_OBJECT (model));
