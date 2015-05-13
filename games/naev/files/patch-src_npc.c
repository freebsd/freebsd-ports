# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/npc.c.orig	2015-02-16 17:49:03 UTC
+++ src/npc.c
@@ -559,7 +559,7 @@ static int npc_approach_giver( NPC_t *np
 
    /* Make sure player can accept the mission. */
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].data == NULL)
+      if (player_missions[i]->data == NULL)
          break;
    if (i >= MISSION_MAX) {
       dialogue_alert("You have too many active missions.");
