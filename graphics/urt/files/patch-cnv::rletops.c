--- cnv/rletops.c.orig	Thu Mar 10 20:09:59 2005
+++ cnv/rletops.c	Thu Mar 10 20:13:29 2005
@@ -74,7 +74,7 @@
     float 	heightinch = 3.0, 
     		center = 3.25, 
     		aspect = 1.0;
-    int 	y, nrow, nscan, i, pix, dummy;
+    int 	nrow, nscan, i, pix, dummy;
     float 	x1, y1, x2, y2, widthinch;
     unsigned char ** scan;
     unsigned char * buffer;
@@ -154,8 +154,7 @@
     y2 = y1 + heightinch;
     prologue(outfile,sflag,nscan,nrow,x1,y1,x2,y2);    
 
-    while ( (y = rle_getrow( &hdr, scan )) <=
-	    hdr.ymax )
+    while ( ( rle_getrow( &hdr, scan )) <= hdr.ymax )
     {
 	if (gencps) {
 	    /* generate a color line */
@@ -231,7 +230,7 @@
 FILE *outfile;
 unsigned char p;
 {
-    static npixo = 0;
+    static int npixo = 0;
     static char tohex[] = "0123456789ABCDEF";
 
     putc(tohex[(p>>4)&0xF],outfile);
