--- plugin.cc.orig
+++ plugin.cc
@@ -109,7 +109,7 @@
 
 static SDL_Surface *opengl_screen = NULL;
 static SDL_Thread *draw_thread = NULL;
-SDL_mutex *mutex = NULL;
+SDL_mutex *sdlmutex = NULL;
 
 VisPlugin dp_vplugin = {
   NULL,                      /* internal    */
@@ -158,14 +158,14 @@
 void
 init_mutexes (void)
 {
-  mutex = SDL_CreateMutex();
+  sdlmutex = SDL_CreateMutex();
 }
 
 
 void
 destroy_mutexes (void)
 {
-  SDL_DestroyMutex(mutex);
+  SDL_DestroyMutex(sdlmutex);
 }
 
 void
@@ -456,14 +456,14 @@
 
   while (!point_general->finished) {
     if (!point_general->paused) {
-      SDL_mutexP(mutex);
+      SDL_mutexP(sdlmutex);
 
 	  update_playlist_info();
 	  look_conf_file();
 	  etoileLoop();
       draw_gl(); 
 
-      SDL_mutexV(mutex);
+      SDL_mutexV(sdlmutex);
       calc_fps();
       calc_max_fps();
       printf("\rFPS: %3.2f", framerate); printf(" ");
