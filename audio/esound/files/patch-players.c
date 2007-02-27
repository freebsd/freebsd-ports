--- players.c.orig	Tue Feb 27 02:16:05 2007
+++ players.c	Tue Feb 27 02:16:37 2007
@@ -310,13 +310,14 @@ int read_player( esd_player_t *player )
 			      player->data_buffer + player->actual_length, 
 			      player->buffer_length - player->actual_length,
 			      actual, "str rd" );
-		if (bytes_read < player->buffer_length - player->actual_length)
-			break;
-		
 		/* check for end of stream */
 		if ( actual == 0 
 		     || ( actual < 0 && errno != EAGAIN && errno != EINTR ) )
 		    return -1;
+
+		if (bytes_read < player->buffer_length - player->actual_length)
+			break;
+		
 		/* more data, save how much we got */
 		if ( actual > 0 )
 		   player->actual_length += actual;
