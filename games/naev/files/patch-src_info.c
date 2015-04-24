# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/info.c.orig	2015-02-16 17:49:03 UTC
+++ src/info.c
@@ -785,8 +785,8 @@ static void cargo_jettison( unsigned int
       /* Get the mission. */
       f = 0;
       for (i=0; i<MISSION_MAX; i++) {
-         for (j=0; j<player_missions[i].ncargo; j++) {
-            if (player_missions[i].cargo[j] == player.p->commodities[pos].id) {
+         for (j=0; j<player_missions[i]->ncargo; j++) {
+            if (player_missions[i]->cargo[j] == player.p->commodities[pos].id) {
                f = 1;
                break;
             }
@@ -799,7 +799,7 @@ static void cargo_jettison( unsigned int
                player.p->commodities[pos].id);
          return;
       }
-      misn = &player_missions[i];
+      misn = player_missions[i];
 
       /* We run the "abort" function if it's found. */
       ret = misn_tryRun( misn, "abort" );
@@ -807,9 +807,7 @@ static void cargo_jettison( unsigned int
       /* Now clean up mission. */
       if (ret != 2) {
          mission_cleanup( misn );
-         memmove( misn, &player_missions[i+1],
-               sizeof(Mission) * (MISSION_MAX-i-1) );
-         memset( &player_missions[MISSION_MAX-1], 0, sizeof(Mission) );
+         mission_shift(pos);
       }
 
       /* Reset markers. */
@@ -1005,8 +1003,10 @@ static void mission_menu_genList( unsign
    misn_names = malloc(sizeof(char*) * MISSION_MAX);
    j = 0;
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].id != 0)
-         misn_names[j++] = (player_missions[i].title!=NULL) ? strdup(player_missions[i].title) : NULL;
+      if (player_missions[i]->id != 0)
+         misn_names[j++] = (player_missions[i]->title != NULL) ?
+               strdup(player_missions[i]->title) : NULL;
+
    if (j==0) { /* no missions */
       misn_names[0] = strdup("No Missions");
       j = 1;
@@ -1035,7 +1035,7 @@ static void mission_menu_update( unsigne
    }
 
    /* Modify the text. */
-   misn = &player_missions[ toolkit_getListPos(wid, "lstMission" ) ];
+   misn = player_missions[ toolkit_getListPos(wid, "lstMission" ) ];
    window_modifyText( wid, "txtReward", misn->reward );
    window_modifyText( wid, "txtDesc", misn->desc );
    window_enableButton( wid, "btnAbortMission" );
@@ -1052,7 +1052,7 @@ static void mission_menu_abort( unsigned
 {
    (void)str;
    int pos;
-   Mission* misn;
+   Mission *misn;
    int ret;
 
    if (dialogue_YesNo( "Abort Mission",
@@ -1060,7 +1060,7 @@ static void mission_menu_abort( unsigned
 
       /* Get the mission. */
       pos = toolkit_getListPos(wid, "lstMission" );
-      misn = &player_missions[pos];
+      misn = player_missions[pos];
 
       /* We run the "abort" function if it's found. */
       ret = misn_tryRun( misn, "abort" );
@@ -1068,9 +1068,7 @@ static void mission_menu_abort( unsigned
       /* Now clean up mission. */
       if (ret != 2) {
          mission_cleanup( misn );
-         memmove( misn, &player_missions[pos+1],
-               sizeof(Mission) * (MISSION_MAX-pos-1) );
-         memset( &player_missions[MISSION_MAX-1], 0, sizeof(Mission) );
+         mission_shift(pos);
       }
 
       /* Reset markers. */
