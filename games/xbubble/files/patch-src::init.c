--- src/init.c.old	Tue Feb  3 18:14:28 2004
+++ src/init.c	Tue Feb  3 18:14:37 2004
@@ -460,7 +460,7 @@
   return return_val;
 }
 
-int diren_select_bubbles (const struct dirent *d) {
+int diren_select_bubbles (struct dirent *d) {
   int color;
   int state;
 
