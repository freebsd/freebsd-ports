--- src/navigate.c.orig	Mon Oct  2 19:13:52 2006
+++ src/navigate.c	Mon Oct  2 19:13:56 2006
@@ -41,7 +41,7 @@
 
 static TimeType step_length = 0;
 
-static gdouble page_divisor = (gdouble) 1.0;
+gdouble page_divisor = (gdouble) 1.0;
 
 /* wave_calculate_zoom_for_span : calculate the zoom factor to show the span of
 	time from `from' to `to'. */
