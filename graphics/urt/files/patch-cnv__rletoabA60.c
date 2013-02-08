--- cnv/rletoabA60.c.orig	1992-01-29 02:54:36.000000000 +0900
+++ cnv/rletoabA60.c	2012-10-13 07:03:23.000000000 +0900
@@ -52,7 +52,7 @@
 rle_pixel scanblu[FRAME_LENGTH][LINE_LENGTH];
 rle_pixel scangrn[FRAME_LENGTH][LINE_LENGTH];
 
-void
+int
 main(argc,argv)
 int argc;
 char **argv;
