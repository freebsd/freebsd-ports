diff --git spel.c spel.c
index 5c53256..1e9ad04 100644
--- spel.c
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
