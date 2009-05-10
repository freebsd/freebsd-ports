--- pngcomp.c.orig	2007-11-12 13:59:38.000000000 +0100
+++ pngcomp.c	2009-05-10 15:07:38.000000000 +0200
@@ -41,6 +41,7 @@
 #include <string.h>
 #include <math.h>
 #include <ctype.h>
+#include <unistd.h>
 
 #include "png.h"
 #include "rwpng.h"
