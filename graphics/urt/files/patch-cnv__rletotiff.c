--- cnv/rletotiff.c.orig	1992-04-30 23:01:10.000000000 +0900
+++ cnv/rletotiff.c	2012-10-15 22:53:31.000000000 +0900
@@ -48,7 +48,7 @@
 static unsigned short compression = COMPRESSION_LZW;
 static int flip = 0;
 
-void
+int
 main(argc, argv)
 int argc;
 char *argv[];
