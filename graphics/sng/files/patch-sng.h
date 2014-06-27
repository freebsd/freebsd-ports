--- sng.h.orig	2014-06-05 17:01:34.835466603 +0100
+++ sng.h	2014-06-05 17:02:02.186256070 +0100
@@ -1,5 +1,7 @@
 /* sng.h -- interface to the SNG compiler */
 
+#include "libpng15/pngpriv.h"
+
 typedef struct color_item_t
 {
     unsigned char r, g, b;
