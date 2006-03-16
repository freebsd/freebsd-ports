--- magnifier/zoom-region.c~	Tue Feb 14 22:37:24 2006
+++ magnifier/zoom-region.c	Thu Mar 16 15:36:55 2006
@@ -1794,10 +1794,10 @@
 		gdk_window_end_paint (zoom_region->priv->w->window);
 		g_timer_stop (mag_timing.scale);
 		if (timing_test) {
-			mag_timing.num_scale_samples++;
-			
 			gulong microseconds;
 
+			mag_timing.num_scale_samples++;
+
 			mag_timing.scale_val =
 			        g_timer_elapsed (mag_timing.scale,
 						 &microseconds);
@@ -1971,12 +1971,11 @@
 	float x_scroll_incr, y_scroll_incr;
 	int width = magnifier->target_bounds.x2 - magnifier->target_bounds.x1;
 	int height = magnifier->target_bounds.y2 - magnifier->target_bounds.y1;
+	gulong microseconds;
 
 	mag_timing.num_frame_samples++;
 	g_timer_stop (mag_timing.frame);
 
-	gulong microseconds;
-
 	mag_timing.frame_val = g_timer_elapsed (mag_timing.frame,
 						&microseconds);
 
@@ -2094,10 +2093,10 @@
 	g_timer_stop (mag_timing.idle);
 
 	if (timing_test) {
-		mag_timing.num_idle_samples++;
-
 		gulong microseconds;
 
+		mag_timing.num_idle_samples++;
+
 		mag_timing.idle_val = g_timer_elapsed (mag_timing.idle,
 						       &microseconds);
 		mag_timing.idle_total += mag_timing.idle_val;
@@ -2472,6 +2471,7 @@
 	int screen_height, height;
 	int pixel_position;
 	int pixel_direction;
+	gulong microseconds;
 
 	screen_height = gdk_screen_get_height (
 		gdk_display_get_screen (magnifier->source_display,
@@ -2484,8 +2484,6 @@
 	roi.x2 = zoom_region->roi.x2;
 
 	g_timer_stop (mag_timing.process);
-
-	gulong microseconds;
 
 	total_time = g_timer_elapsed (mag_timing.process, &microseconds);
 
