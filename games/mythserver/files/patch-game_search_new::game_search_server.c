--- game_search_new/game_search_server.c.orig	Sat Feb  9 15:00:01 2002
+++ game_search_new/game_search_server.c	Sat Feb  9 15:02:05 2002
@@ -20,7 +20,9 @@
 #include "game_search_packets.h"
 #include "games_list.h"
 
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <arpa/inet.h>
