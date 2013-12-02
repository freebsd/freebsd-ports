--- app/text/gimpfont.c.orig	2013-12-02 21:01:06.000000000 +0100
+++ app/text/gimpfont.c	2013-12-02 21:01:47.000000000 +0100
@@ -27,7 +27,9 @@
 
 #define PANGO_ENABLE_ENGINE  1   /* Argh */
 #include <pango/pango-ot.h>
-#include <freetype/tttables.h>
+
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 
 #include "text-types.h"
 
