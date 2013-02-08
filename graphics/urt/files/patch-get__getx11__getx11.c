--- get/getx11/getx11.c.orig	1995-01-11 06:16:18.000000000 +0900
+++ get/getx11/getx11.c	2012-10-13 07:08:08.000000000 +0900
@@ -218,7 +218,7 @@
  *	[None]
  */
 
-void
+int
 main (argc, argv)
 int		argc;
 char 		** argv;
