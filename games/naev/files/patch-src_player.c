# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers
# Origin: https://github.com/naev/naev/commit/34651062f0f26b43489214137862148c7cf842c1
# Subject: Regenerate the player's ship list when removing a ship

--- src/player.c.orig	2015-03-05 22:11:11 UTC
+++ src/player.c
@@ -665,7 +665,7 @@ credits_t player_shipPrice( char* shipna
  */
 void player_rmShip( char* shipname )
 {
-   int i;
+   int i, w;
 
    for (i=0; i<player_nstack; i++) {
       /* Not the ship we are looking for. */
@@ -684,6 +684,12 @@ void player_rmShip( char* shipname )
       player_stack = realloc( player_stack,
             sizeof(PlayerShip_t) * (player_nstack) );
    }
+
+   /* Update ship list if landed. */
+   if (landed) {
+      w = land_getWid( LAND_WINDOW_EQUIPMENT );
+      equipment_regenLists( w, 0, 1 );
+   }
 }
 
 
@@ -3011,11 +3017,11 @@ static int player_saveShip( xmlTextWrite
          found = 0;
          for (j=0; j<MISSION_MAX; j++) {
             /* Only check active missions. */
-            if (player_missions[j].id > 0) {
+            if (player_missions[j]->id > 0) {
                /* Now check if it's in the cargo list. */
-               for (k=0; k<player_missions[j].ncargo; k++) {
+               for (k=0; k<player_missions[j]->ncargo; k++) {
                   /* See if it matches a cargo. */
-                  if (player_missions[j].cargo[k] == ship->commodities[i].id) {
+                  if (player_missions[j]->cargo[k] == ship->commodities[i].id) {
                      found = 1;
                      break;
                   }
