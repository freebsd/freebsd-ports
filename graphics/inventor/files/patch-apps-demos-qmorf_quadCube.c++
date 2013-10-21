--- apps/demos/qmorf/quadCube.c++.orig	2013-10-10 14:58:48.000000000 +0200
+++ apps/demos/qmorf/quadCube.c++	2013-10-10 14:58:56.000000000 +0200
@@ -182,7 +182,7 @@
     return result;
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     if (argc > 1) diagonalFlag = 0;
 
