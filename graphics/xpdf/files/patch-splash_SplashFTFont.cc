--- splash/SplashFTFont.cc.orig	Tue Feb 27 14:05:52 2007
+++ splash/SplashFTFont.cc
@@ -229,7 +229,7 @@
 };
 
 SplashPath *SplashFTFont::getGlyphPath(int c) {
-  static FT_Outline_Funcs outlineFuncs = {
+  static const FT_Outline_Funcs outlineFuncs = {
 #if FREETYPE_MINOR <= 1
     (int (*)(FT_Vector *, void *))&glyphPathMoveTo,
     (int (*)(FT_Vector *, void *))&glyphPathLineTo,
