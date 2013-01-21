--- cnv/rletoiris.c.orig	1992-04-30 22:59:53.000000000 +0900
+++ cnv/rletoiris.c	2012-10-16 00:19:07.000000000 +0900
@@ -32,6 +32,7 @@
 
 rle_hdr hdr;
 
+int
 main(argc,argv)
 int argc;
 char *argv[];
