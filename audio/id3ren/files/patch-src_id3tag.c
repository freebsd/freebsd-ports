--- src/id3tag.c.orig	2012-05-15 20:31:03 UTC
+++ src/id3tag.c
@@ -363,6 +363,7 @@ get_tag_string (int size, char *def_stri
     return TRUE;
   }
 
+  memset(string, 0, size);
   fgets(string, size, stdin);
 
   if (string[strlen(string)-1] == '\n')
