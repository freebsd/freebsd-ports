--- vm/readln.c	Wed Aug 13 16:31:55 2003
+++ vm/readln.c.patch	Sun Sep 14 00:58:08 2003
@@ -43,7 +43,7 @@
   char** matches=(char**) NULL;
   
   if (start == 0)
-    matches = rl_completion_matches (text, command_generator);
+    matches = (char **)completion_matches (text, command_generator);
 
   return (matches);
 }
