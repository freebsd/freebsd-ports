--- apps/tools/ivinfo/ivinfo.c++.orig	2013-10-10 14:56:40.000000000 +0200
+++ apps/tools/ivinfo/ivinfo.c++	2013-10-10 14:56:45.000000000 +0200
@@ -159,7 +159,7 @@
     }
 }
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     SoInput	in;
     SoNode	*root;
