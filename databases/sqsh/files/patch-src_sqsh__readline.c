--- src/sqsh_readline.c.orig	2012-03-29 16:25:46.000000000 +0000
+++ src/sqsh_readline.c
@@ -145,7 +145,7 @@ int sqsh_readline_init()
 
     rl_readline_name                 = "sqsh" ;
     rl_completion_entry_function     = (rl_compentry_func_t*)sqsh_completion ;
-    rl_attempted_completion_function = (CPPFunction*)sqsh_completion ;
+    rl_attempted_completion_function = (rl_completion_func_t *)sqsh_completion ;
 
     /*
      * sqsh-2.1.8 - Remove '@' and '$' from the readline default list of word break
