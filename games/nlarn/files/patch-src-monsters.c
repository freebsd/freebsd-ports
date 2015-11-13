--- src/monsters.c.orig	2012-07-06 17:29:35 UTC
+++ src/monsters.c
@@ -2725,6 +2725,11 @@ static position monster_move_serve(monst
             map_path_element *pe = g_queue_pop_head(path->path);
             npos = pe->pos;
         }
+        else
+        {
+            /* ensure npos is initialized */
+            npos = m->pos;
+        }
 
         if (path != NULL)
             map_path_destroy(path);
