--- src/raknet/RakPeer.cpp.orig	2013-03-28 17:46:00.000000000 +0100
+++ src/raknet/RakPeer.cpp	2013-03-28 17:55:11.000000000 +0100
@@ -1060,7 +1060,6 @@
 
 	for ( ; index < banList.size(); index++ )
 	{
-		delete [] banList[ index ]->IP;
 		delete [] banList[ index ];
 	}
 
