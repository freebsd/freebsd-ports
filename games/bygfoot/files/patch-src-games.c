--- src/games.c.orig	Mon Jul 12 10:33:02 2004
+++ src/games.c	Sat Jul 17 14:05:39 2004
@@ -436,9 +436,6 @@
     gint i;
     gfloat random = rnd(0,1);
 
-    if(debug && fix.team_id[team] == my_team)
-	return;
-
     player *pl =
 	&(teams[fix.team_id[team]].players[player_number]);
 
@@ -454,6 +451,9 @@
        in weeks: 1,2,3,4 or 5 */
     gfloat duration[6]={0,0.7,0.85,0.95,0.975,1};
 
+    if(debug && fix.team_id[team] == my_team)
+	return;
+
     /* injured or banned players don't really participate
        in the game */
     if(!pl->cskill ||
@@ -496,9 +496,6 @@
     gint i;
     gfloat random = rnd(0,1);
     
-    if(debug && fix.team_id[team] == my_team)
-	return;
-
     /* for convenience, so as not to write
        teams[fix.team_id[team]].players[player_number]
        each time */
@@ -538,6 +535,9 @@
 			  {4,12},{5,12},{6,16},{3,8},
 			  {5,14},{12,30}};
     
+    if(debug && fix.team_id[team] == my_team)
+	return;
+
     for(i=1;i<12;i++)
 	if(injury_probs[i - 1] * prob < random &&
 	   random <= injury_probs[i] * prob &&
