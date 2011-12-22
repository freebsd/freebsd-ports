--- shell/xQuery.c.orig	2011-12-22 00:24:32.000000000 +0800
+++ shell/xQuery.c	2011-12-22 00:24:43.000000000 +0800
@@ -83,7 +83,7 @@ void packerquery(unsigned int packerid)
   printf("\n");
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   struct XpkPackerList list;
   int i;
