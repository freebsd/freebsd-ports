--- src/songaccess.h.orig	Mon Jan 17 00:08:56 2005
+++ src/songaccess.h	Thu Mar 31 19:52:57 2005
@@ -58,7 +58,6 @@
 	void store(Song song);
 	void remove(string key);
 
-	using LPDatabaseReader::retrieve; //unhide retrieve(song)
 	/** looks up the song in the database */
 	Song retrieve(string key);
 
