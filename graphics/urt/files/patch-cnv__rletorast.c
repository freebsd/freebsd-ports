--- cnv/rletorast.c.orig	1992-01-21 03:11:32.000000000 +0900
+++ cnv/rletorast.c	2012-10-16 00:15:02.000000000 +0900
@@ -41,7 +41,7 @@
 
 typedef	enum { GREY, GREY_ALPHA, COLOR, COLOR_ALPHA } Input_Type ;
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
