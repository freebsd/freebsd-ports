--- splash/SplashFTFont.cc.orig	2005-12-23 16:57:18.076514614 +0100
+++ splash/SplashFTFont.cc	2005-12-23 17:33:42.731318339 +0100
@@ -14,7 +14,8 @@
 
 #include <ft2build.h>
 #include FT_OUTLINE_H
-#include FT_INTERNAL_OBJECTS_H // needed for FT_New_Size decl
+#include FT_SIZES_H // needed for FT_New_Size decl
+#include FT_GLYPH_H
 #include "gmem.h"
 #include "SplashMath.h"
 #include "SplashGlyphBitmap.h"
@@ -25,11 +26,12 @@
 
 //------------------------------------------------------------------------
 
-static int glyphPathMoveTo(FT_Vector *pt, void *path);
-static int glyphPathLineTo(FT_Vector *pt, void *path);
-static int glyphPathConicTo(FT_Vector *ctrl, FT_Vector *pt, void *path);
-static int glyphPathCubicTo(FT_Vector *ctrl1, FT_Vector *ctrl2,
-			    FT_Vector *pt, void *path);
+static int glyphPathMoveTo( const FT_Vector *pt, void *path);
+static int glyphPathLineTo( const FT_Vector *pt, void *path);
+static int glyphPathConicTo( const FT_Vector *ctrl, const FT_Vector *pt,
+                             void* path );
+static int glyphPathCubicTo( const FT_Vector *ctrl1, const FT_Vector *ctrl2,
+			     const FT_Vector *pt, void *path);
 
 //------------------------------------------------------------------------
 // SplashFTFont
@@ -210,7 +212,7 @@
 };
 
 SplashPath *SplashFTFont::getGlyphPath(int c) {
-  static FT_Outline_Funcs outlineFuncs = {
+  static const FT_Outline_Funcs outlineFuncs = {
     &glyphPathMoveTo,
     &glyphPathLineTo,
     &glyphPathConicTo,
@@ -249,7 +251,7 @@
   return path.path;
 }
 
-static int glyphPathMoveTo(FT_Vector *pt, void *path) {
+static int glyphPathMoveTo( const FT_Vector *pt, void *path) {
   SplashFTFontPath *p = (SplashFTFontPath *)path;

   if (p->needClose) {
@@ -260,7 +262,7 @@
   return 0;
 }
 
-static int glyphPathLineTo(FT_Vector *pt, void *path) {
+static int glyphPathLineTo(const FT_Vector *pt, void *path) {
   SplashFTFontPath *p = (SplashFTFontPath *)path;
 
   p->path->lineTo(pt->x / 64.0, -pt->y / 64.0);
@@ -268,7 +270,7 @@
   return 0;
 }
 
-static int glyphPathConicTo(FT_Vector *ctrl, FT_Vector *pt, void *path) {
+static int glyphPathConicTo(const FT_Vector *ctrl, const FT_Vector *pt, void *path) {
   SplashFTFontPath *p = (SplashFTFontPath *)path;
   SplashCoord x0, y0, x1, y1, x2, y2, x3, y3, xc, yc;
 
@@ -306,8 +308,8 @@
   return 0;
 }
 
-static int glyphPathCubicTo(FT_Vector *ctrl1, FT_Vector *ctrl2,
-			    FT_Vector *pt, void *path) {
+static int glyphPathCubicTo(const FT_Vector *ctrl1, const FT_Vector *ctrl2,
+			    const FT_Vector *pt, void *path) {
   SplashFTFontPath *p = (SplashFTFontPath *)path;
 
   p->path->curveTo(ctrl1->x / 64.0, -ctrl1->y / 64.0,
