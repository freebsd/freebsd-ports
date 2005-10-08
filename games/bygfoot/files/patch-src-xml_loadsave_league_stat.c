--- src/xml_loadsave_league_stat.c.orig	Sat Sep 10 11:30:49 2005
+++ src/xml_loadsave_league_stat.c	Sat Oct  8 12:19:24 2005
@@ -20,7 +20,7 @@
 
 gint state, in_state, valueidx;
 Stat new_stat;
-LeagueStat *lstat;
+LeagueStat *leag_stat;
 
 void
 xml_loadsave_league_stat_start_element (GMarkupParseContext *context,
@@ -80,13 +80,13 @@
     {	
 	state = in_state;
 	if(in_state == TAG_STAT_TEAMS_OFF)
-	    stat_array = lstat->teams_off;
+	    stat_array = leag_stat->teams_off;
 	else if(in_state == TAG_STAT_TEAMS_DEF)
-	    stat_array = lstat->teams_def;
+	    stat_array = leag_stat->teams_def;
 	else if(in_state == TAG_STAT_PLAYER_SCORERS)
-	    stat_array = lstat->player_scorers;
+	    stat_array = leag_stat->player_scorers;
 	else if(in_state == TAG_STAT_PLAYER_GOALIES)
-	    stat_array = lstat->player_goalies;
+	    stat_array = leag_stat->player_goalies;
 	else
 	{
 	    g_warning("xml_loadsave_league_stat_end_element: unknown in_state %d \n", 
@@ -126,7 +126,7 @@
     int_value = (gint)g_ascii_strtod(buf, NULL);
 
     if(state == TAG_ID)
-	lstat->clid = int_value;
+	leag_stat->clid = int_value;
     else if(state == TAG_TEAM_ID)
 	new_stat.team_id = int_value;
     else if(state == TAG_STAT_VALUE)
@@ -162,7 +162,7 @@
 	misc_print_error(&error, TRUE);
     }
 
-    lstat = league_stat;
+    leag_stat = league_stat;
 
     if(g_markup_parse_context_parse(context, file_contents, length, &error))
     {
