--- cnv/rletopaint.c.orig	1992-05-22 00:11:41.000000000 +0900
+++ cnv/rletopaint.c	2012-10-15 22:42:40.000000000 +0900
@@ -74,7 +74,7 @@
 int compress_line();
 void write_paint_line(), bytes_to_bits();
 
-void
+int
 main(argc, argv)
 int argc;
 char *argv[];
