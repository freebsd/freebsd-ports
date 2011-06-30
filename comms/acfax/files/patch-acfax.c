--- acfax.c.orig	2011-06-30 14:39:10.000000000 -0400
+++ acfax.c	2011-06-30 14:39:23.000000000 -0400
@@ -739,7 +739,7 @@
     exit(0);
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   int i;
   Pixel respix[20];
