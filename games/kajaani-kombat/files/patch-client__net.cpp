--- client_net.cpp.orig	2005-01-22 16:51:34 UTC
+++ client_net.cpp
@@ -31,13 +31,13 @@ client_tcpnet::client_tcpnet(IPaddress *
   assert (ret != -1);
 
   cond = SDL_CreateCond();
-  if (cond <0)
+  if (cond == NULL)
     {
       fprintf (stderr, "Error creating cond variable\n");
       exit(2);
     }
   mutex = SDL_CreateMutex();
-  if (mutex < 0)
+  if (mutex == NULL)
     {
       fprintf (stderr, "Error creating mutex\n");
       exit(2);
@@ -45,13 +45,13 @@ client_tcpnet::client_tcpnet(IPaddress *
 
   active = true;
   trans_th = SDL_CreateThread (&client_tcpnet::transf_func, (void *) this);
-  if (trans_th < 0)
+  if (trans_th == NULL)
     {
       fprintf(stderr, "Error starting thread: %s\n", SDL_GetError());
       exit(2);
     }
   input_th = SDL_CreateThread (&client_tcpnet::input_func, (void *) this);
-  if (input_th < 0)
+  if (input_th == NULL)
     {
       fprintf(stderr, "Error starting thread: %s\n", SDL_GetError());
       exit(2);
