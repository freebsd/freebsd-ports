--- tools/rleinterp.c.orig	1992-04-30 23:12:20.000000000 +0900
+++ tools/rleinterp.c	2012-10-15 22:56:39.000000000 +0900
@@ -38,6 +38,7 @@
 extern char *optarg;
 extern int optind;
 
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -48,8 +49,8 @@
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
