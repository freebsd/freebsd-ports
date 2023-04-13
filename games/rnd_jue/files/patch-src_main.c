--- src/main.c.orig	2023-04-13 09:22:55 UTC
+++ src/main.c
@@ -41,11 +41,11 @@ SDL_Thread	       *server_thread;
 int			key_joystick_mapping = 0;
 
 #if 1
-boolean			redraw[MAX_LEV_FIELDX + 2][MAX_LEV_FIELDY + 2];
+extern boolean		redraw[MAX_LEV_FIELDX + 2][MAX_LEV_FIELDY + 2];
 #else
-boolean			redraw[MAX_BUF_XSIZE][MAX_BUF_YSIZE];
+extern boolean		redraw[MAX_BUF_XSIZE][MAX_BUF_YSIZE];
 #endif
-int			redraw_x1 = 0, redraw_y1 = 0;
+extern int		redraw_x1 = 0, redraw_y1 = 0;
 
 short			Feld[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 short			MovPos[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
@@ -75,7 +75,7 @@ short			ExplodeDelay[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			RunnerVisit[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			PlayerVisit[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 
-int			GfxFrame[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
+extern int		GfxFrame[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int 			GfxRandom[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int 			GfxElement[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
 int			GfxAction[MAX_LEV_FIELDX][MAX_LEV_FIELDY];
@@ -131,7 +131,7 @@ struct LevelInfo	level, level_template;
 struct PlayerInfo	stored_player[MAX_PLAYERS], *local_player = NULL;
 struct HiScore		highscore[MAX_SCORE_ENTRIES];
 struct TapeInfo		tape;
-struct SetupInfo	setup;
+extern struct SetupInfo	setup;
 struct GameInfo		game;
 struct GlobalInfo	global;
 struct BorderInfo	border;
