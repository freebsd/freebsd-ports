--- src/genius-readline-helper.c.orig	2009-10-19 01:06:52.000000000 +0000
+++ src/genius-readline-helper.c
@@ -164,7 +164,7 @@ main(int argc, char *argv[])
 	rl_terminal_name = "xterm";
 	rl_readline_name = "Genius";
 	rl_attempted_completion_function =
-		(CPPFunction *)tab_completion;
+		(rl_completion_func_t *)tab_completion;
 
 	while(fgets(buf,4096,infp)) {
 		int count;
