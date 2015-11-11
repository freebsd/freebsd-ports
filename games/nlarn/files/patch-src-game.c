--- src/game.c.orig	2012-07-06 17:29:35 UTC
+++ src/game.c
@@ -1353,7 +1353,7 @@ static void game_scores_save(game *g, GL
     if (sb == NULL)
     {
         /* opening the file failed */
-        log_add_entry(g->log, "Error opening scoreboard file \"%s\".");
+        log_add_entry(g->log, "Error opening scoreboard file.");
         free(uscores);
         return;
     }
