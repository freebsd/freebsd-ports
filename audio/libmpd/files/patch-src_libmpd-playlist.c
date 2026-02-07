--- src/libmpd-playlist.c.orig	2011-08-17 12:31:47 UTC
+++ src/libmpd-playlist.c
@@ -780,7 +780,7 @@ int mpd_playlist_load(MpdObj *mi, const char *path)
 	if(mpd_lock_conn(mi))
 	{
 		debug_printf(DEBUG_ERROR,"lock failed\n");
-		return NULL;
+		return 0;
 	}
     mpd_sendLoadCommand(mi->connection,path);
 	mpd_finishCommand(mi->connection);
