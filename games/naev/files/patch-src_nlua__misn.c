# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers
# Origin: https://github.com/naev/naev/commit/155a7fdaf07e1b5549e6314a433425b4187bb33f
# Subject: Don't use a pointer to a pointer

--- src/nlua_misn.c.orig	2015-02-16 17:49:03 UTC
+++ src/nlua_misn.c
@@ -283,13 +283,13 @@ int misn_runFunc( Mission *misn, const c
    if (misn_delete) {
       ret = 2;
       mission_cleanup( cur_mission );
-      for (i=0; i<MISSION_MAX; i++)
-         if (cur_mission == &player_missions[i]) {
-            memmove( &player_missions[i], &player_missions[i+1],
-                  sizeof(Mission) * (MISSION_MAX-i-1) );
-            memset( &player_missions[MISSION_MAX-1], 0, sizeof(Mission) );
-            break;
-         }
+      for (i=0; i<MISSION_MAX; i++) {
+         if (cur_mission != player_missions[i])
+            continue;
+
+         mission_shift(i);
+         break;
+      }
    }
 
    return ret;
@@ -609,7 +609,7 @@ static int misn_accept( lua_State *L )
 
    /* find last mission */
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].data == NULL)
+      if (player_missions[i]->data == NULL)
          break;
 
    cur_mission = misn_getFromLua(L);
@@ -620,9 +620,9 @@ static int misn_accept( lua_State *L )
    else if (i>=MISSION_MAX)
       ret = 1;
    else { /* copy it over */
-      memcpy( &player_missions[i], cur_mission, sizeof(Mission) );
+      memcpy( player_missions[i], cur_mission, sizeof(Mission) );
       memset( cur_mission, 0, sizeof(Mission) );
-      cur_mission = &player_missions[i];
+      cur_mission = player_missions[i];
       cur_mission->accepted = 1; /* Mark as accepted. */
 
       /* Need to change pointer. */
