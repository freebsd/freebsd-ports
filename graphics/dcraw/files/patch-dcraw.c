--- dcraw.c.orig	Sat Jan 21 11:47:53 2006
+++ dcraw.c	Mon Jan 23 16:23:23 2006
@@ -1140,8 +1140,9 @@
 void CLASS layer_thumb (FILE *tfp)
 {
   int i, c;
+  char *thumb;
   colors = thumb_misc >> 5;
-  char *thumb = malloc (thumb_length*colors);
+  thumb = malloc (thumb_length*colors);
   merror (thumb, "layer_thumb()");
   fprintf (tfp, "P%d\n%d %d\n255\n",
 	5 + (thumb_misc >> 6), thumb_width, thumb_height);
