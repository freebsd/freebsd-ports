--- src/image.h.orig	2021-12-03 16:02:51 UTC
+++ src/image.h
@@ -22,5 +22,6 @@ void image_putc(engine_t *en, const char c);
 void image_set_foreground(engine_t *p, const rgb_t* color);
 void image_fill_rect(engine_t *en, const image_point_t x1, const image_point_t y1, const image_point_t x2, const image_point_t y2);
 void image_move_to(engine_t *en, const image_point_t x, const image_point_t y);
+void image_show_text(engine_t *en, const char* text);
 
 #endif
