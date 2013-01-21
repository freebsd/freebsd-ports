--- tools/crop.c.orig	1992-04-30 23:09:41.000000000 +0900
+++ tools/crop.c	2012-10-15 22:52:09.000000000 +0900
@@ -35,7 +35,7 @@
 extern void rle_box();
 int pos_box_vals();
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];
