--- ../../src/socket.c.orig	2008-05-10 13:14:59.000000000 +0300
+++ ../../src/socket.c	2008-05-10 13:15:04.000000000 +0300
@@ -706,7 +706,9 @@
     start_timer = SDL_GetTicks();
     while (connect(*socket_temp, (struct sockaddr *) &insock, sizeof(insock)) == -1)
     {
-        SDL_Delay(3);
+	// EINPROGRESS leads to EALREADY over few iterations
+	if (errno == EALREADY) break;
+        SDL_Delay(30);
         /* timeout.... without connect will REALLY hang a long time */
         if (start_timer + SOCKET_TIMEOUT_MS < SDL_GetTicks())
         {
