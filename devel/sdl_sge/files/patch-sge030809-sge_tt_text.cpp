--- sge_tt_text.cpp.orig	Fri Aug  8 08:48:08 2003
+++ sge_tt_text.cpp	Wed Oct  4 11:43:47 2006
@@ -36,10 +36,10 @@
 #include "sge_textpp.h"
 
 #ifndef _SGE_NOTTF
-#include <freetype/freetype.h>
-#include <freetype/ftoutln.h>
-#include <freetype/ttnameid.h>
-#include <freetype/internal/ftobjs.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_OUTLINE_H
+#include FT_TRUETYPE_IDS_H
 
 /* The structure used to hold glyph information (cached) */
 struct glyph {
@@ -294,7 +294,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = _sge_library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
