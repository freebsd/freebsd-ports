--- cnv/rletorla.c.orig	2012-10-16 00:51:43.000000000 +0900
+++ cnv/rletorla.c	2012-10-16 01:00:52.000000000 +0900
@@ -29,9 +29,13 @@
  * System includes.
  */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 #include "rlb_header.h"
 #include "rle.h"
 
+#if 0
 #ifdef USE_STDLIB_H
 #include <stdlib.h>
 #else
@@ -52,6 +56,7 @@
 extern void free();
 
 #endif /* USE_STDLIB_H */
+#endif
 
 #define VPRINTF if (verbose || header) fprintf
 #define GRAYSCALE   001	/* 8 bits, no colormap */
@@ -312,7 +317,7 @@
    U_CHAR	*buf;
    int		*offset;
    int		width, height;
-   int		scan, x, y;
+   int		scan, x;
    short	len;
    long		offptr;
 /*
@@ -348,7 +353,7 @@
       exit(-1);
       }
    for (scan = 0; scan < height; scan++) {
-      y = rle_getrow(&rle_dflt_hdr, scanline);
+      (void)rle_getrow(&rle_dflt_hdr, scanline);
       switch (visual) {
          case GRAYSCALE:	/* 8 bits without colormap */
                red   = scanline[0];
