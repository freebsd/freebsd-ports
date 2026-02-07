--- ./aishmv.c.orig	1998-03-19 15:55:50.000000000 +0100
+++ ./aishmv.c	2012-08-24 11:55:08.781914503 +0200
@@ -348,7 +348,7 @@
 #else
 void
 main( argc, argv )
-unsigned char	**argv;
+char	**argv;
 #endif
 {
 	unsigned char	ptr[RBSIZE];
