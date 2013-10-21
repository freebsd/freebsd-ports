--- apps/tools/ivcat/ivcat.c++.orig	2013-10-10 14:54:27.000000000 +0200
+++ apps/tools/ivcat/ivcat.c++	2013-10-10 14:54:37.000000000 +0200
@@ -215,7 +215,7 @@
     }
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     int expandFileNodes = 0;
     int expandTextureNodes = 0;
