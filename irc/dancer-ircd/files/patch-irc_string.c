This patch prevents ircd from stripping topics etc. of escape
characters, which is commonly used by Asian languages.

--- src/irc_string.c.orig	Sun Apr  7 08:16:04 2002
+++ src/irc_string.c	Tue Apr 15 23:52:28 2003
@@ -131,6 +131,7 @@
 
 char* strip_colour(char* string)
 {
+#if 0
   char *c = string;
   char *c2 = string;
   char *last_non_space = c2;
@@ -165,6 +166,7 @@
   *c2 = '\0';
   if (last_non_space)
     *last_non_space = '\0';
+#endif
   return string;
 }
 
