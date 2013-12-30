--- src/lib/engines/common/evas_font_load.c.orig	2013-12-14 12:42:42.000000000 +0100
+++ src/lib/engines/common/evas_font_load.c	2013-12-14 12:44:14.000000000 +0100
@@ -5,7 +5,8 @@
 
 #include "evas_font_private.h" /* for Frame-Queuing support */
 #include "evas_font_ot.h"
-#include <freetype/tttables.h> /* Freetype2 OS/2 font table. */
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H /* Freetype2 OS/2 font table. */
 
 #ifdef EVAS_CSERVE2
 # include "../../cserve2/evas_cs2_private.h"
