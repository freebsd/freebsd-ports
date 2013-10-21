--- apps/samples/widgets/componentTest.c++.orig	2013-10-10 14:53:45.000000000 +0200
+++ apps/samples/widgets/componentTest.c++	2013-10-10 14:53:54.000000000 +0200
@@ -60,7 +60,7 @@
 }
 
 int
-main(unsigned int argc, char *argv[])
+main(int argc, char *argv[])
 {
     if (argc != 2)
 	usage(argv[0]);
