--- apps/demos/qmorf/quadSphere.c++.orig	2013-10-10 14:58:13.000000000 +0200
+++ apps/demos/qmorf/quadSphere.c++	2013-10-10 14:58:20.000000000 +0200
@@ -76,7 +76,7 @@
     return result;
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     SoDB::init();
 
