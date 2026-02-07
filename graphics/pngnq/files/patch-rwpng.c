--- src/rwpng.c.orig	2010-05-11 00:42:56.000000000 +0200
+++ src/rwpng.c	2012-04-25 19:10:41.000000000 +0200
@@ -33,6 +33,7 @@
 #include <stdlib.h>
 
 #include "png.h"        /* libpng header; includes zlib.h */
+#include "zlib.h"
 #include "rwpng.h"      /* typedefs, common macros, public prototypes */
 
 /* future versions of libpng will provide this macro: */
