# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/nlua_hook.c.orig	2015-03-17 16:29:43 UTC
+++ src/nlua_hook.c
@@ -246,7 +246,7 @@ static unsigned int hook_generic( lua_St
    if (running_mission != NULL) {
       /* make sure mission is a player mission */
       for (i=0; i<MISSION_MAX; i++)
-         if (player_missions[i].id == running_mission->id)
+         if (player_missions[i]->id == running_mission->id)
             break;
       if (i>=MISSION_MAX) {
          WARN("Mission not in stack trying to hook, forgot to run misn.accept()?");
