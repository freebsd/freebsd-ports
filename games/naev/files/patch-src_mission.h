# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/mission.h.orig	2015-02-16 17:49:03 UTC
+++ src/mission.h
@@ -129,7 +129,7 @@ typedef struct Mission_ {
  * current player missions
  */
 #define MISSION_MAX  12 /**< No sense in allowing the player have infinite missions. */
-extern Mission player_missions[MISSION_MAX]; /**< Player's active missions. */
+extern Mission *player_missions[MISSION_MAX]; /**< Player's active missions. */
 
 
 /*
@@ -165,6 +165,7 @@ int mission_unlinkCargo( Mission* misn, 
  */
 int missions_load (void);
 void mission_cleanup( Mission* misn );
+void mission_shift( int pos );
 void missions_free (void);
 void missions_cleanup (void);
 
