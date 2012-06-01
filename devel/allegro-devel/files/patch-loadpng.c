--- addons/loadpng/loadpng.c.orig	2010-03-03 04:18:36.000000000 +0100
+++ addons/loadpng/loadpng.c	2012-04-25 19:36:29.000000000 +0200
@@ -6,6 +6,7 @@
 
 
 #include <png.h>
+#include <zlib.h>
 #include <allegro.h>
 #include <allegro/internal/aintern.h>
 #include "loadpng.h"
