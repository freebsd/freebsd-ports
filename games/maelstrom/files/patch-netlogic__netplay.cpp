--- ./netlogic/netplay.cpp.orig	2002-10-20 06:11:52.000000000 +0200
+++ ./netlogic/netplay.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -670,7 +670,9 @@
 		strcpy(message, "Waiting for players:");
 		for ( i=0; i<gNumPlayers; ++i ) {
 			if ( ! acked[i] )
-				sprintf(&message[strlen(message)], " %d", i+1);
+				snprintf(&message[strlen(message)],
+					 sizeof(message)-strlen(message),
+					 " %d", i+1);
 		}
 		Message(message);
 
@@ -725,7 +727,7 @@
 			/* Check the player... */
 			if ( (i != gOurPlayer) && (netbuf[1] == gOurPlayer) ) {
 				/* Print message, sleep 3 seconds absolutely */
-				sprintf(message, 
+			  snprintf(message, sizeof(message),
 	"Error: Another player (%d) thinks they are player 1!\r\n", i+1);
 				ErrorMessage(message);
 				/* Suck up retransmission packets */
