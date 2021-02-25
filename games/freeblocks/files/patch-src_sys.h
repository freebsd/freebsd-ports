--- src/sys.h.orig	2015-03-09 12:48:31 UTC
+++ src/sys.h
@@ -99,62 +99,63 @@ enum KEYBINDS {
 
 extern const char* const key_desc[];
 
-SDL_Surface* screen;
-TTF_Font* font;
+extern SDL_Surface* screen;
+extern TTF_Font* font;
 
-int score;
-int high_scores[10];
-bool title_screen;
-bool high_scores_screen;
-int options_screen;
-bool game_over;
-bool paused;
-bool quit;
-int game_mode;
+extern int score;
+extern int high_scores[10];
+extern bool title_screen;
+extern bool high_scores_screen;
+extern int options_screen;
+extern bool game_over;
+extern bool paused;
+extern bool quit;
+extern int game_mode;
 
 struct Cursor {
     int x1;
     int y1;
     int x2;
     int y2;
-}cursor;
+};
+extern struct Cursor cursor;
 
-int action_cooldown;
+extern int action_cooldown;
 typedef enum {
     ACTION_NONE, ACTION_LEFT, ACTION_RIGHT, ACTION_UP, ACTION_DOWN
 }ActionMove;
-ActionMove action_move;
-ActionMove action_last_move;
-ActionMove action_switch;
-bool action_bump;
-bool action_accept;
-bool action_pause;
-bool action_exit;
+extern ActionMove action_move;
+extern ActionMove action_last_move;
+extern bool action_switch;
+extern bool action_bump;
+extern bool action_accept;
+extern bool action_pause;
+extern bool action_exit;
 
-Dork_String path_dir_config;
-Dork_String path_file_config;
-Dork_String path_file_highscores;
-Dork_String path_file_highscores_jewels;
+extern Dork_String path_dir_config;
+extern Dork_String path_file_config;
+extern Dork_String path_file_highscores;
+extern Dork_String path_file_highscores_jewels;
 
-int option_joystick;
-int option_sound;
-int option_music;
-int option_fullscreen;
+extern int option_joystick;
+extern int option_sound;
+extern int option_music;
+extern int option_fullscreen;
 
-SDLKey option_key[9];
-int option_joy_button[5];
-int option_joy_axis_x;
-int option_joy_axis_y;
+extern SDLKey option_key[9];
+extern int option_joy_button[5];
+extern int option_joy_axis_x;
+extern int option_joy_axis_y;
 
-SDLKey last_key;
-int last_joy_button;
+extern SDLKey last_key;
+extern int last_joy_button;
 
-SDL_Event event;
+extern SDL_Event event;
 
 // Timers
-unsigned int startTimer;
-unsigned int endTimer;
-unsigned int deltaTimer;
+extern unsigned int startTimer;
+extern unsigned int endTimer;
+extern unsigned int deltaTimer;
 
 // Functions
 bool sysInit();
@@ -176,26 +177,26 @@ void sysHighScoresSave();
 void sysHighScoresClear();
 
 // Images
-SDL_Surface* surface_blocks;
-SDL_Surface* surface_clear;
-SDL_Surface* surface_cursor;
-SDL_Surface* surface_cursor_highlight;
-SDL_Surface* surface_bar;
-SDL_Surface* surface_bar_inactive;
-SDL_Surface* surface_background;
-SDL_Surface* surface_background_jewels;
-SDL_Surface* surface_title;
-SDL_Surface* surface_highscores;
+extern SDL_Surface* surface_blocks;
+extern SDL_Surface* surface_clear;
+extern SDL_Surface* surface_cursor;
+extern SDL_Surface* surface_cursor_highlight;
+extern SDL_Surface* surface_bar;
+extern SDL_Surface* surface_bar_inactive;
+extern SDL_Surface* surface_background;
+extern SDL_Surface* surface_background_jewels;
+extern SDL_Surface* surface_title;
+extern SDL_Surface* surface_highscores;
 
 // Music and Sounds
-Mix_Music* music;
-Mix_Music* music_jewels;
-Mix_Chunk* sound_menu;
-Mix_Chunk* sound_switch;
-Mix_Chunk* sound_match;
-Mix_Chunk* sound_drop;
+extern Mix_Music* music;
+extern Mix_Music* music_jewels;
+extern Mix_Chunk* sound_menu;
+extern Mix_Chunk* sound_switch;
+extern Mix_Chunk* sound_match;
+extern Mix_Chunk* sound_drop;
 
 // Joystick
-SDL_Joystick* joy;
+extern SDL_Joystick* joy;
 
 #endif
