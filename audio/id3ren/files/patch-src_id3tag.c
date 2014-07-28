--- src/id3tag.c.orig	Fri Jan  7 09:32:59 2005
+++ src/id3tag.c	Fri Jan  7 09:33:14 2005
@@ -369,6 +369,7 @@
     return TRUE;
   }
 
+  memset(string, 0, size);
   fgets(string, size, stdin);
 
   if (string[strlen(string)-1] == '\n')
