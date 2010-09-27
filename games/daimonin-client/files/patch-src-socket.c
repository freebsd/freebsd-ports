--- ../../src/socket.c.orig	2010-08-22 16:53:22.000000000 -0400
+++ ../../src/socket.c	2010-09-20 15:04:30.000000000 -0400
@@ -728,6 +728,7 @@
         memcpy(&insock.sin_addr, hostbn->h_addr, hostbn->h_length);
     }
 
+#if 0
     // Set non-blocking.
     flags = fcntl(*socket_temp, F_GETFL);
     if (fcntl(*socket_temp, F_SETFL, flags | O_NONBLOCK) == -1)
@@ -736,11 +737,14 @@
         *socket_temp = SOCKET_NO;
         return(FALSE);
     }
+#endif
     // Try to connect.
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
@@ -749,6 +753,7 @@
             return(FALSE);
         }
     }
+#if 0
     // Set back to blocking.
     if (fcntl(*socket_temp, F_SETFL, flags) == -1)
     {
@@ -756,6 +761,7 @@
         *socket_temp = SOCKET_NO;
         return(FALSE);
     }
+#endif
 #else
 struct addrinfo hints;
 struct addrinfo *res = NULL, *ai;
@@ -786,6 +792,7 @@
         *socket_temp = SOCKET_NO;
         continue;
     }
+#if 0
     // Set non-blocking.
     flags = fcntl(*socket_temp, F_GETFL);
     if (fcntl(*socket_temp, F_SETFL, flags | O_NONBLOCK) == -1)
@@ -794,11 +801,14 @@
         *socket_temp = SOCKET_NO;
         return(FALSE);
     }
+#endif
     // Try to connect.
     start_timer = SDL_GetTicks();
     while (connect(*socket_temp, ai->ai_addr, ai->ai_addrlen) != 0)
     {
-        SDL_Delay(3);
+	// EINPROGRESS leads to EALREADY over few iterations
+	if (errno == EALREADY) break;
+        SDL_Delay(30);
         /* timeout.... without connect will REALLY hang a long time */
         if (start_timer + SOCKET_TIMEOUT_MS < SDL_GetTicks())
         {
@@ -807,6 +817,7 @@
             goto next_try;
         }
     }
+#if 0
     // Set back to blocking.
     if (fcntl(*socket_temp, F_SETFL, flags) == -1)
     {
@@ -814,6 +825,7 @@
         *socket_temp = SOCKET_NO;
         return(FALSE);
     }
+#endif
     break;
 next_try:
     ;
