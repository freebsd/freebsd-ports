--- siconv.c.orig	Tue Mar 27 00:55:22 2001
+++ siconv.c	Tue Mar 27 01:02:20 2001
@@ -139,7 +139,7 @@
 void usage(void) {
   printf("usage:\n");
   printf("\n");
-  printf("  convert stdin from iso-8859-1 to utf8 on stdout\n");
+  printf("  convert stdin from iso-8859-1 to utf-8 on stdout\n");
   printf("  $ siconv\n");
   printf("  convert stdin from charset-A to charset-B on stdout\n");
   printf("  $ siconv charset-A charset-B\n");
@@ -149,7 +149,7 @@
 
 int main(int argc, char *argv[]) {
   char *from = "iso-8859-1";
-  char *to = "unicode";
+  char *to = "utf-8";
 
   if ( argc == 3 ) {
     from = argv[1];
