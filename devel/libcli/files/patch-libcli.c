diff --git a/libcli.c b/libcli.c
index de6e2e9..59dd42f 100644
--- libcli.c
+++ libcli.c
@@ -1017,7 +1017,7 @@ static int cli_get_completions(struct cli_def *cli, const char *command, char **
 {
     struct cli_command *c;
     struct cli_command *n;
-    int num_words, i, k=0;
+    int num_words, save_words, i, k=0;
     char *words[CLI_MAX_LINE_WORDS] = {0};
     int filter = 0;
 
@@ -1025,12 +1025,12 @@ static int cli_get_completions(struct cli_def *cli, const char *command, char **
     while (isspace(*command))
         command++;
 
-    num_words = cli_parse_line(command, words, sizeof(words)/sizeof(words[0]));
+    save_words = num_words = cli_parse_line(command, words, sizeof(words)/sizeof(words[0]));
     if (!command[0] || command[strlen(command)-1] == ' ')
         num_words++;
 
     if (!num_words)
-        return 0;
+        goto out;
 
     for (i = 0; i < num_words; i++)
     {
@@ -1043,7 +1043,7 @@ static int cli_get_completions(struct cli_def *cli, const char *command, char **
         unsigned len = 0;
 
         if (filter < num_words - 1) // filter already completed
-            return 0;
+            goto out;
 
         if (filter == num_words - 1)
             len = strlen(words[num_words-1]);
@@ -1055,7 +1055,7 @@ static int cli_get_completions(struct cli_def *cli, const char *command, char **
         }
 
         completions[k] = NULL;
-        return k;
+        goto out;
     }
 
     for (c = cli->commands, i = 0; c && i < num_words && k < max_completions; c = n)
@@ -1084,6 +1084,10 @@ static int cli_get_completions(struct cli_def *cli, const char *command, char **
         completions[k++] = c->command;
     }
 
+out:
+    for (i = 0; i < save_words; i++)
+        free(words[i]);
+
     return k;
 }
 
-- 
1.7.10

