--- src/sys.c.orig	2015-03-09 12:48:31 UTC
+++ src/sys.c
@@ -52,6 +52,7 @@ TTF_Font* font = NULL;
 SDL_Surface* surface_blocks = NULL;
 SDL_Surface* surface_clear = NULL;
 SDL_Surface* surface_cursor = NULL;
+SDL_Surface* surface_cursor_highlight = NULL;
 SDL_Surface* surface_cursor_single = NULL;
 SDL_Surface* surface_bar = NULL;
 SDL_Surface* surface_bar_inactive = NULL;
@@ -68,6 +69,7 @@ Mix_Chunk* sound_drop = NULL;
 SDL_Joystick* joy = NULL;
 
 int score = 0;
+int high_scores[10];
 bool title_screen = true;
 bool high_scores_screen = false;
 int options_screen = -1;
@@ -77,15 +79,22 @@ bool quit = false;
 
 int game_mode = GAME_MODE_DEFAULT;
 
+struct Cursor cursor;
+
 int action_cooldown = 0;
 ActionMove action_move = ACTION_NONE;
 ActionMove action_last_move = ACTION_NONE;
-ActionMove action_switch = ACTION_NONE;
+bool action_switch = false;
 bool action_bump = false;
 bool action_accept = false;
 bool action_pause = false;
 bool action_exit = false;
 
+Dork_String path_dir_config;
+Dork_String path_file_config;
+Dork_String path_file_highscores;
+Dork_String path_file_highscores_jewels;
+
 int option_joystick = -1;
 int option_sound = 8;
 int option_music = 8;
@@ -96,8 +105,20 @@ int option_fullscreen = 1;
 int option_fullscreen = 0;
 #endif
 
+SDLKey option_key[9];
+int option_joy_button[5];
+int option_joy_axis_x;
+int option_joy_axis_y;
+
 SDLKey last_key = SDLK_UNKNOWN;
 int last_joy_button = -1;
+
+SDL_Event event;
+
+// Timers
+unsigned int startTimer;
+unsigned int endTimer;
+unsigned int deltaTimer;
 
 bool sysInit() {
     if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
