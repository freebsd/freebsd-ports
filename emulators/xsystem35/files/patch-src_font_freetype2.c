--- src/font_freetype2.c.orig	Mon Jul 21 04:30:16 2003
+++ src/font_freetype2.c	Sat Aug 14 05:11:39 2004
@@ -26,7 +26,8 @@
 #include <stdio.h>
 #include <string.h>
 #include <glib.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "portab.h"
 #include "system.h"
