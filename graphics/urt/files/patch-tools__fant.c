--- tools/fant.c.orig	1992-04-30 23:09:59.000000000 +0900
+++ tools/fant.c	2012-10-15 22:52:09.000000000 +0900
@@ -116,7 +116,7 @@
 void getraster(), xform_image(), putraster(), clear_raster(), xform_points();
 
 
-void
+int
 main(argc,argv)
 int argc;
 char *argv[];
