--- src/game.c.orig	2012-07-06 20:29:35.000000000 +0300
+++ src/game.c	2013-03-09 12:23:13.000000000 +0200
@@ -1353,7 +1354,7 @@
     if (sb == NULL)
     {
         /* opening the file failed */
-        log_add_entry(g->log, "Error opening scoreboard file \"%s\".");
+        log_add_entry(g->log, "Error opening scoreboard file.");
         free(uscores);
         return;
     }
