--- src/network.c.orig	2011-05-04 00:15:17 UTC
+++ src/network.c
@@ -54,7 +54,7 @@ static int connected_server = -1;
 static int my_index = -1;
 
 /* Keep track of other connected players: */
-lan_player_type lan_player_info[MAX_CLIENTS];
+lan_player_type lan_player_info[MAX_CLIENTS];
 
 /* Local function prototypes: */
 int say_to_server(char *statement);
