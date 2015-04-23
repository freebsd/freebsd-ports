# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/hook.c.orig	2015-02-16 17:49:03 UTC
+++ src/hook.c
@@ -837,8 +837,8 @@ static Mission *hook_getMission( Hook *h
 {
    int i;
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].id == hook->u.misn.parent)
-         return &player_missions[i];
+      if (player_missions[i]->id == hook->u.misn.parent)
+         return player_missions[i];
 
    return NULL;
 }
