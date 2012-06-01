--- util/cairoutils.c.orig	2012-04-25 05:33:34.000000000 +0200
+++ util/cairoutils.c	2012-04-25 05:35:29.000000000 +0200
@@ -25,6 +25,7 @@
 
 #include <cairo.h>
 #include <png.h>
+#include <zlib.h>
 #include <jpeglib.h>
 
 #include "an-bool.h"
