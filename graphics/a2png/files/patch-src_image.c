--- src/image.c.orig	2006-10-05 13:36:26 UTC
+++ src/image.c
@@ -148,7 +148,6 @@ void image_resize_crop(engine_t *e, const int width_px
 	#endif
 }
 
-inline
 void image_set_foreground(engine_t *p, const rgb_t* color) {
 	#ifdef ENABLE_CAIRO
 	static const double alpha = 1.0;
@@ -286,7 +285,6 @@ image_points_t image_get_font_max_metrics(engine_t *p,
 	return r;
 }
 
-inline
 void image_move_to(engine_t *en, const image_point_t x, const image_point_t y) {
 	en->pos.x = x;
 	en->pos.y = y;
@@ -296,7 +294,6 @@ void image_move_to(engine_t *en, const image_point_t x
 	#endif
 }
 
-inline
 image_points_t image_get_position(engine_t *en) {
 	#ifdef ENABLE_CAIRO
 	static image_points_t r;
