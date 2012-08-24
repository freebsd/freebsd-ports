--- ./aish.c.orig	1998-03-19 16:14:04.000000000 +0100
+++ ./aish.c	2012-08-24 11:54:45.144913079 +0200
@@ -64,7 +64,7 @@
 #else
 void
 main( argc, argv )
-unsigned char	**argv;
+char	**argv;
 #endif
 {
 	unsigned char	ptr[RBSIZE];
