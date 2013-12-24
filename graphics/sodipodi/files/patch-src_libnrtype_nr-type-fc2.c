--- src/libnrtype/nr-type-ft2.c.orig	2013-12-16 01:48:18.000000000 +0100
+++ src/libnrtype/nr-type-ft2.c	2013-12-16 01:49:11.000000000 +0100
@@ -13,8 +13,9 @@
 #include <stdio.h>
 #include <libnr/nr-macros.h>
 #include <libnr/nr-matrix.h>
-#include <freetype/ftoutln.h>
-#include <freetype/ftbbox.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
+#include FT_BBOX_H
 #include "nr-type-ft2.h"
 
 #define noNRTFFT2_DEBUG
