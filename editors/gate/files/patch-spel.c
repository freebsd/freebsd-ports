--- spel.c.orig	2003-06-19 16:55:51 UTC
+++ spel.c
@@ -151,7 +151,7 @@ empty_repl()
 /* ADD_REPL - Add the given replacement to the list of replacements.
  * "replace" may be NULL to indicate that the word is to be ignored.
  */
-
+void
 add_repl(char *word, int word_len, char *replace)
 {
     struct repl *r;
@@ -683,7 +683,7 @@ int fix_word(char *line, int offset, int
     for(;;)
     {
 	subtask= 1;
-	if (getline(bf,NULL,&wcol,st))
+	if (get_line(bf,NULL,&wcol,st))
 	{
 	    printf("\nSpell Check Interupted.\n");
 	    return 1;
