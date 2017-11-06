--- game_server.cpp.orig	2005-05-30 10:25:51 UTC
+++ game_server.cpp
@@ -64,7 +64,7 @@ void game_server::init_net()
   
   // OK, init server thread to listen to clients
   con_th = SDL_CreateThread (&game_server::connection_accepter, (void *) this);
-  if (con_th < 0)
+  if (con_th == NULL)
     {
       fprintf (stderr, "[SRV] Error starting thread: %s\n", SDL_GetError());
       exit(2);
