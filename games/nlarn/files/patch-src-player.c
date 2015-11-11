--- src/player.c.orig	2012-07-06 17:29:35 UTC
+++ src/player.c
@@ -1605,6 +1605,11 @@ int player_map_enter(player *p, map *l, 
         else
             pos = map_find_sobject(l, LS_STAIRSUP);
     }
+    /* doing nothing? */
+    else
+    {
+        pos = p->pos;
+    }
 
     if (l->nlevel == 0)
     {
