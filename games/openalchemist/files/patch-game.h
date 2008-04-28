--- includes/game.h.orig	2008-03-18 17:50:34.816043102 +0100
+++ includes/game.h	2008-03-18 17:50:57.531984095 +0100
@@ -219,47 +219,47 @@
   public:
 
   //Constructor
-  Game::Game(CL_DisplayWindow *window, bool opengl);
+  Game(CL_DisplayWindow *window, bool opengl);
   //Destructor
-  Game::~Game();
+  ~Game();
 
   // Some methods
-  void Game::choose_skin();
-  void Game::load_gfx();
-  void Game::unload_gfx();
-  void Game::toggle_screen();
-  void Game::main_loop();
+  void choose_skin();
+  void load_gfx();
+  void unload_gfx();
+  void toggle_screen();
+  void main_loop();
 
   // Methods to draw the game
-  void Game::draw_game();  
-  void Game::draw_playing();
-  void Game::draw_falling();
-  void Game::draw_destroying();
-  void Game::draw_to_playing();
-  void Game::draw_game_over();
-  void Game::draw_new_hightscore();
-  void Game::draw_pause();
+  void draw_game();  
+  void draw_playing();
+  void draw_falling();
+  void draw_destroying();
+  void draw_to_playing();
+  void draw_game_over();
+  void draw_new_hightscore();
+  void draw_pause();
   
-  void Game::draw_progress_bar();
-  void Game::draw_skins_selector();
+  void draw_progress_bar();
+  void draw_skins_selector();
 
-  void Game::calc_score();
+  void calc_score();
  
-  void Game::load_preferences();
-  void Game::save_preferences();
-  void Game::read_scores();
-  void Game::save_scores();
-  void Game::key_events();
-  void Game::key_events_playing();
-  void Game::key_events_pause();
-  void Game::key_events_skins_selector();
-  void Game::undo_last();
-  void Game::new_game(short difficulty);
-  void Game::fall();
-  void Game::detect_to_destroy();
-  void Game::detect_to_fall();
+  void load_preferences();
+  void save_preferences();
+  void read_scores();
+  void save_scores();
+  void key_events();
+  void key_events_playing();
+  void key_events_pause();
+  void key_events_skins_selector();
+  void undo_last();
+  void new_game(short difficulty);
+  void fall();
+  void detect_to_destroy();
+  void detect_to_fall();
 
-  void Game::stop();
+  void stop();
 
 };
 
