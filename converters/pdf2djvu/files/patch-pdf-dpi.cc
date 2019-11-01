--- pdf-dpi.cc.orig	2019-10-27 19:10:07 UTC
+++ pdf-dpi.cc
@@ -34,7 +34,7 @@ class DpiGuessDevice : public pdf::OutputDevice (prote
   }
 
   virtual void drawImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
-    pdf::gfx::ImageColorMap *color_map, bool interpolate, int *mask_colors, bool inline_image)
+    pdf::gfx::ImageColorMap *color_map, bool interpolate, const int *mask_colors, bool inline_image)
   {
     this->process_image(state, width, height);
   }
