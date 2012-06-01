--- jbig2_image_png.c.orig	2009-07-16 06:44:49.000000000 +0200
+++ jbig2_image_png.c	2012-04-24 21:54:55.000000000 +0200
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <png.h>
+#include <pngpriv.h>
 
 #include "jbig2.h"
 #include "jbig2_priv.h"
