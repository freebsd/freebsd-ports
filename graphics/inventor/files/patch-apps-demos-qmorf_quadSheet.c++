--- apps/demos/qmorf/quadSheet.c++.orig	2013-10-10 14:59:43.000000000 +0200
+++ apps/demos/qmorf/quadSheet.c++	2013-10-10 14:59:47.000000000 +0200
@@ -68,7 +68,7 @@
     return result;
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     SoDB::init();
 
