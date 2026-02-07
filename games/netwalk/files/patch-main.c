--- main.c.orig	2013-09-24 05:25:27 UTC
+++ main.c
@@ -107,7 +107,7 @@ SDL_Surface *screen;
 TTF_Font *font;
 int lastmousex, lastmousey;
 char *player_name;
-int game_won;
+extern int game_won;
 int state;
 
 struct button_s {
