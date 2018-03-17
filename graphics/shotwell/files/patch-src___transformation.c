--- src/_transformation.c.orig	2018-03-17 15:06:02 UTC
+++ src/_transformation.c
@@ -7,7 +7,7 @@
 
 #include "shotwell-graphics-processor.h"
 
-inline void _pixel_transformer_apply_transformations (PixelTransformer* self, RGBAnalyticPixel* p, RGBAnalyticPixel* result) {
+void _pixel_transformer_apply_transformations (PixelTransformer* self, RGBAnalyticPixel* p, RGBAnalyticPixel* result) {
     PixelFormat current_format = PIXEL_FORMAT_RGB;
     RGBAnalyticPixel p_rgb = {p->red, p->green, p->blue };
     HSVAnalyticPixel p_hsv = {0.0f, 0.0f, 0.0f};
