--- src/irc_string.c.orig	Tue Jul  8 14:41:54 2003
+++ src/irc_string.c	Tue Apr 20 00:33:19 2004
@@ -139,6 +139,7 @@
 
 char* strip_colour(char* string)
 {
+#if 0
   char *c = string;
   char *c2 = string;
   char *last_non_space = NULL;
@@ -173,6 +174,7 @@
   *c2 = '\0';
   if (last_non_space)
     *last_non_space = '\0';
+#endif
   return string;
 }
 
