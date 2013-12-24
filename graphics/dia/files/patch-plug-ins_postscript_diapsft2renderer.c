--- plug-ins/postscript/diapsft2renderer.c.orig	2013-12-14 12:29:51.000000000 +0100
+++ plug-ins/postscript/diapsft2renderer.c	2013-12-14 12:31:31.000000000 +0100
@@ -29,8 +29,9 @@
 #include <pango/pangoft2.h>
 #include <pango/pango-engine.h>
 /* I'd really rather avoid this */
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 
 #define DPI 300
 
