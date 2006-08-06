diff -ur sge030809_orig/sge_tt_text.cpp sge030809/sge_tt_text.cpp
--- sge030809_orig/sge_tt_text.cpp	Fri Aug  8 14:48:08 2003
+++ sge_tt_text.cpp	Sun Jul 30 20:49:29 2006
@@ -36,9 +36,10 @@
 #include "sge_textpp.h"
 
 #ifndef _SGE_NOTTF
-#include <freetype/freetype.h>
-#include <freetype/ftoutln.h>
-#include <freetype/ttnameid.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_OUTLINE_H
+#include FT_TRUETYPE_IDS_H
 #include <freetype/internal/ftobjs.h>
 
 /* The structure used to hold glyph information (cached) */
