--- marlin/marlin-sample-view.c.orig	Sun Aug  8 00:41:40 2004
+++ marlin/marlin-sample-view.c	Wed Aug 11 20:01:45 2004
@@ -157,6 +157,9 @@
 			 guint64 new_position,
 			 gboolean extend_selection);
 
+void marlin_sample_view_vzoom_in (MarlinSampleView *view);
+void marlin_sample_view_vzoom_out (MarlinSampleView *view);
+
 /* Stuff to register the coverage enum */
 #define MARLIN_TYPE_COVERAGE (coverage_get_type ())
 static GType
