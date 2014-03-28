--- o/gcl_readline.d.orig
+++ o/gcl_readline.d
@@ -221,7 +221,7 @@
    in case we want to do some simple parsing.  Return the array of matches,
    or NULL if there aren't any. */
 /* extern char **rl_completion_matches(char *,char *(*)(char *,int)); */
-static char **rl_completion(char *text, int start, int end) {
+static char **rl_completion(const char *text, int start, int end) {
 	return rl_completion_matches(text, (rl_compentry_func_t *)rl_completion_words_new);
 }
 #endif
@@ -469,7 +469,7 @@
   char *pn="GCL",*cp=getenv("TERM");
   rl_readline_name=pn;
 #ifdef RL_COMPLETION
-  rl_attempted_completion_function = (CPPFunction *)rl_completion;
+  rl_attempted_completion_function = rl_completion;
 #endif		
   if (isatty(0) && (!cp || strcmp(cp,"dumb")))
     readline_on=1;
