--- gucharmap/gucharmap-window.c.orig	Thu Nov 20 21:26:42 2003
+++ gucharmap/gucharmap-window.c	Thu Nov 20 21:27:03 2003
@@ -113,8 +113,8 @@
 {
   const gchar *no_leading_space, *nptr;
   char *endptr;
-  g_assert (direction == -1 || direction == 1);
   gunichar wc;
+  g_assert (direction == -1 || direction == 1);
 
   if (search_text[0] == '\0')
     {
