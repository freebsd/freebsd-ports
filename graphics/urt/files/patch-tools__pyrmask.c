--- tools/pyrmask.c.orig	1992-01-24 01:26:23.000000000 +0900
+++ tools/pyrmask.c	2012-10-15 22:52:09.000000000 +0900
@@ -20,7 +20,7 @@
 void alloc_pyramid(), copy_mask_bands(), rebuild_image(), dump_pyramid();
 void copy_half_bands();
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
