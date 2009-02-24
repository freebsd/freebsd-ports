--- cairomm/fontface.cc.orig	2009-02-24 02:40:24.000000000 -0500
+++ cairomm/fontface.cc	2009-02-24 02:49:31.000000000 -0500
@@ -309,7 +309,7 @@ UserFontFace::text_to_glyphs(const RefPt
   // bool value in the user_data, which we can read back in the
   // text_to_glyphs_cb and used as a signal to return -1 for the num_glyphs
   // parameter.
-  cairo_font_face_set_user_data(cobj(), &USER_DATA_KEY_DEFAULT_TEXT_TO_GLYPHS, reinterpret_cast<void*>(true), NULL);
+  cairo_font_face_set_user_data(cobj(), &USER_DATA_KEY_DEFAULT_TEXT_TO_GLYPHS, (void *) (true), NULL);
   return CAIRO_STATUS_SUCCESS;
 }
 
