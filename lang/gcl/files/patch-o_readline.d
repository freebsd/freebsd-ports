--- ./o/readline.d.orig	Sat Jul 20 08:10:56 2002
+++ ./o/readline.d	Sat Sep 13 23:52:24 2003
@@ -94,7 +94,7 @@
    the word to complete.  We can use the entire contents of rl_line_buffer
    in case we want to do some simple parsing.  Return the array of matches,
    or NULL if there aren't any. */
-extern char **completion_matches(char *,char *(*)(char *,int));
+/*extern char **completion_matches(char *,char *(*)(char *,int));*/
 static char **rl_completion(char *text, int start, int end) {
 	return completion_matches(text, rl_completion_words);
 }
