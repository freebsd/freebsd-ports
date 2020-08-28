--- showbuf.c.orig	1995-11-23 07:01:36.000000000 -0500
+++ showbuf.c	2013-06-12 17:15:47.000000000 -0400
@@ -210,7 +210,7 @@
 	fprintf(ofp,"90 rotate 0 %d translate ", - papersize[paper].width);
     fprintf(ofp," %f 1 scale\n",HOR_SCALE_FAC);
 
-    if(nobox == False) 
+    if(nobox == False) {
        if(layout==Sero) {
    	box(p_lm, p_bm, p_width, p_height);
    	fillbox(p_lm, p_bm, s_width, p_height);
@@ -236,6 +236,7 @@
    	fillbox(l3_lm2, l3_bm, s_width, l3_height);
    	fillbox(l3_lm3, l3_bm, s_width, l3_height);
        }
+    }
     if(noheader == False) {
        x = (layout==Sero||layout==Sero2) ?  p_lm : l_lm1;
        y = (layout==Sero||layout==Sero2) ?  p_tm : l_tm;
