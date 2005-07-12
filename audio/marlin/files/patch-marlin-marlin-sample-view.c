--- marlin/marlin-sample-view.c.orig	Mon Jul 11 21:28:23 2005
+++ marlin/marlin-sample-view.c	Wed Jul 13 00:36:31 2005
@@ -177,6 +177,10 @@
 			 guint64 new_position,
 			 gboolean extend_selection);
 
+void marlin_sample_view_vzoom_in (MarlinSampleView *view);
+void marlin_sample_view_vzoom_out (MarlinSampleView *view);
+void scroll_to (MarlinSampleView *view, int x);
+
 /* Stuff to register the coverage enum */
 #define MARLIN_TYPE_COVERAGE (coverage_get_type ())
 static GType
