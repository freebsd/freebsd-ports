--- src/inter.c.orig	2009-04-19 23:44:43.000000000 +0000
+++ src/inter.c
@@ -368,5 +368,5 @@ init_inter(void)
 {
 	rl_readline_name = "Genius";
 	rl_attempted_completion_function =
-		(CPPFunction *)tab_completion;
+		(rl_completion_func_t *)tab_completion;
 }
