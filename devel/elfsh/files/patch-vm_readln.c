--- vm/readln.c.orig	2003-08-21 01:11:03 UTC
+++ vm/readln.c
@@ -43,7 +43,7 @@ char** coustom_completion(const char* te
   char** matches=(char**) NULL;
   
   if (start == 0)
-    matches = rl_completion_matches (text, command_generator);
+    matches = (char **)completion_matches (text, command_generator);
 
   return (matches);
 }
