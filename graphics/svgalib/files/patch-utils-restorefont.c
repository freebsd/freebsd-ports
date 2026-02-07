--- utils/restorefont.c.orig	2011-07-01 01:35:42.000000000 +0200
+++ utils/restorefont.c	2011-07-01 01:36:05.000000000 +0200
@@ -11,7 +11,7 @@
  * given up). This means that there is no major security hole lurking here.
  */
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     FILE *f;
     unsigned char *font;
