--- shell/xQuery.c.orig	2000-04-15 00:37:42 UTC
+++ shell/xQuery.c
@@ -83,7 +83,7 @@ void packerquery(unsigned int packerid)
   printf("\n");
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   struct XpkPackerList list;
   int i;
