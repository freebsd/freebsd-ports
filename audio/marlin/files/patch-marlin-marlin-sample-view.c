--- marlin/marlin-sample-view.c.orig	Tue Jul 12 17:57:56 2005
+++ marlin/marlin-sample-view.c	Wed Jul 13 17:51:32 2005
@@ -179,6 +179,9 @@
 static void scroll_to (MarlinSampleView *view,
 		       int x);
 
+void marlin_sample_view_vzoom_in (MarlinSampleView *view);
+void marlin_sample_view_vzoom_out (MarlinSampleView *view);
+
 /* Stuff to register the coverage enum */
 #define MARLIN_TYPE_COVERAGE (coverage_get_type ())
 static GType
