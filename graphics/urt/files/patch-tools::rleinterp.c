--- tools/rleinterp.c.orig	Thu Mar 10 21:14:52 2005
+++ tools/rleinterp.c	Thu Mar 10 21:15:40 2005
@@ -48,8 +48,8 @@
 		nom_sortie[BUFSIZ],
     		extension[80] ,
     	       *basenom, *rep ;
-    int  i, ni, n, nbimage=1;
-    int  rle_err, width, y, x ;
+    int  i, n, nbimage=1;
+    int  width, y, x ;
     int  iflag1 = 0 , iflag2 = 0, oflag = 0, fd ;
     double alpha, beta ;
     FILE        * outfile;
