--- src/main.c.orig	2018-04-10 19:44:08 UTC
+++ src/main.c
@@ -69,7 +69,7 @@ short			ExplodeDelay[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			RunnerVisit[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			PlayerVisit[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 
-int			GfxFrame[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
+extern int			GfxFrame[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int 			GfxRandom[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int 			GfxElement[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			GfxAction[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
@@ -138,7 +138,7 @@ struct LevelInfo	level, level_template;
 struct PlayerInfo	stored_player[MAX_PLAYERS], *local_player = NULL;
 struct HiScore		highscore[MAX_SCORE_ENTRIES];
 struct TapeInfo		tape;
-struct SetupInfo	setup;
+extern struct SetupInfo	setup;
 struct GameInfo		game;
 struct GlobalInfo	global;
 struct BorderInfo	border;
