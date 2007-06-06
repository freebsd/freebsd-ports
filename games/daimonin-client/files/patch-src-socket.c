--- ../../src/socket.c.orig	Sun May 20 02:10:22 2007
+++ ../../src/socket.c	Thu Jun  7 01:09:08 2007
@@ -706,6 +706,8 @@
     start_timer = SDL_GetTicks();
     while (connect(*socket_temp, (struct sockaddr *) &insock, sizeof(insock)) == -1)
     {
+	// EINPROGRESS leads to EALREADY over few iterations
+	if (errno == EALREADY) break;
         SDL_Delay(3);
         /* timeout.... without connect will REALLY hang a long time */
         if (start_timer + SOCKET_TIMEOUT_MS < SDL_GetTicks())
