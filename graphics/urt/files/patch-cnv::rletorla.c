--- cnv/rletorla.c.orig	Thu Mar 10 23:41:56 2005
+++ cnv/rletorla.c	Thu Mar 10 23:39:39 2005
@@ -312,7 +312,7 @@
    U_CHAR	*buf;
    int		*offset;
    int		width, height;
-   int		scan, x, y;
+   int		scan, x;
    short	len;
    long		offptr;
 /*
@@ -348,7 +348,7 @@
       exit(-1);
       }
    for (scan = 0; scan < height; scan++) {
-      y = rle_getrow(&rle_dflt_hdr, scanline);
+      (void)rle_getrow(&rle_dflt_hdr, scanline);
       switch (visual) {
          case GRAYSCALE:	/* 8 bits without colormap */
                red   = scanline[0];
