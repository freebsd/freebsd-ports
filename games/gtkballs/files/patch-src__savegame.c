--- ./src/savegame.c.orig	2003-05-21 18:06:05.000000000 +0200
+++ ./src/savegame.c	2014-03-30 20:05:17.338033553 +0200
@@ -166,7 +166,7 @@
         if((f = fopen(fname, "w")) != NULL) {
                 chmod(fname, 0600);
                 /* TODO: check for errors ! */
-                fprintf(f, rules);
+                fprintf(f, "%s", rules);
                 fprintf(f, "%010d", score);
                 for(i = 0; i < rules_get_width() * rules_get_height(); i++) {
                 	fprintf(f, "%02d", board[i]);
