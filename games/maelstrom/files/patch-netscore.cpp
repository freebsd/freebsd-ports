--- ./netscore.cpp.orig	2001-07-23 05:25:17.000000000 +0200
+++ ./netscore.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -59,7 +59,7 @@
 
 	/* Send the scores */
 	crc = get_checksum(key, KEY_LEN);
-	sprintf(netbuf, SCOREFMT, crc, high.name, high.score, high.wave);
+	snprintf(netbuf, sizeof(netbuf), SCOREFMT, crc, high.name, high.score, high.wave);
 	SDLNet_TCP_Send(remote, netbuf, strlen(netbuf));
 	n = SDLNet_TCP_Recv(remote, netbuf, 1024);
 	if ( n > 0 ) {
