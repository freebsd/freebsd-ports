--- src/savegame.c.orig	2003-05-21 16:06:05 UTC
+++ src/savegame.c
@@ -166,7 +166,7 @@ gchar *save_game(gchar *rules, gint scor
         if((f = fopen(fname, "w")) != NULL) {
                 chmod(fname, 0600);
                 /* TODO: check for errors ! */
-                fprintf(f, rules);
+                fprintf(f, "%s", rules);
                 fprintf(f, "%010d", score);
                 for(i = 0; i < rules_get_width() * rules_get_height(); i++) {
                 	fprintf(f, "%02d", board[i]);
