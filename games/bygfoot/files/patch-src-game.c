--- src/game.c.orig	Sun Jan 30 22:00:18 2005
+++ src/game.c	Mon Jan 31 22:10:46 2005
@@ -528,14 +528,7 @@
 			 gint player_number)
 {
     gint i;
-    gfloat rndom = rnd(0,1);
-
-    if(debug && fix.team_id[team] == my_team)
-	return;
-
-    player *pl =
-	&(teams[fix.team_id[team]].players[player_number]);
-
+    player *pl;
     /* probabilities that a player
        with cpos i is sent off: prob[i][0];
        booked with yellow: prob[i][1] - bookprob[i][0] */
@@ -549,6 +542,14 @@
     gfloat duration[6]={0,0.7,0.85,0.95,0.975,1};
 
     gfloat increasing_factor = 1.0;
+    gfloat rndom = rnd(0,1);
+
+    if(debug && fix.team_id[team] == my_team)
+	return;
+
+    pl =
+	&(teams[fix.team_id[team]].players[player_number]);
+
     if (options[OPT_BOOST] && fix.team_id[team] == my_team)
     	increasing_factor = BOOST_CARD_EFFECT;
 
