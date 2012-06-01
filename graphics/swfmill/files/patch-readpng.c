--- src/swft/readpng.c.orig	2009-11-30 01:18:53.000000000 +0100
+++ src/swft/readpng.c	2012-05-05 07:48:08.000000000 +0200
@@ -51,6 +51,7 @@
 #include <stdlib.h>
 
 #include "png.h"        /* libpng header; includes zlib.h */
+#include "zlib.h"
 #include "readpng.h"    /* typedefs, common macros, public prototypes */
 
 /* future versions of libpng will provide this macro: */
@@ -87,7 +88,7 @@
      * have used slightly more general png_sig_cmp() function instead */
 
     fread(sig, 1, 8, infile);
-    if (!png_check_sig(sig, 8))
+    if (png_sig_cmp(sig, 0, 8))
         return 1;   /* bad signature */
 
 
