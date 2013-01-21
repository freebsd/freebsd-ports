--- tools/unexp.c.orig	1992-01-24 05:58:37.000000000 +0900
+++ tools/unexp.c	2012-10-15 23:04:14.000000000 +0900
@@ -24,7 +24,7 @@
 rle_hdr in_hdr, out_hdr;
 rle_pixel r_in, g_in, b_in;
 
-void
+int
 main(argc,argv)
 int argc;
 char *argv[];
