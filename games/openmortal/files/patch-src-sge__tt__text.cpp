--- src/sge_tt_text.cpp.orig	2004-03-03 21:17:48.000000000 +0100
+++ src/sge_tt_text.cpp	2013-12-13 11:24:58.000000000 +0100
@@ -26,7 +26,6 @@
 
 #include "SDL.h"
 #include <stdlib.h>
-#include <malloc.h>
 #include <memory.h>
 #include <string.h>
 #include <stdarg.h>
@@ -37,9 +36,9 @@
 
 #ifndef _SGE_NOTTF
 #include <ft2build.h>
-#include <freetype/freetype.h>
-#include <freetype/ftoutln.h>
-#include <freetype/ttnameid.h>
+#include FT_FREETYPE_H
+#include FT_OUTLINE_H
+#include FT_TRUETYPE_IDS_H
 
 /* The structure used to hold glyph information (cached) */
 struct glyph {
