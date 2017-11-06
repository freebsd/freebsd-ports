Reset seek position for BGM with more than 64 tracks

--- source/gamelib/packfile.c.orig	2011-09-28 01:05:05 UTC
+++ source/gamelib/packfile.c
@@ -1137,7 +1137,7 @@ void packfile_music_read(fileliststruct *filelist, int
 		getBasePath(packfile, filelist[i].filename, 1);
 		if(stristr(packfile, ".pak"))
 		{
-			memset(filelist[i].bgmTracks, 0, 256);
+			memset(filelist[i].bgmTracks, 0, sizeof(filelist[i].bgmTracks));
 			filelist[i].nTracks = 0;
 			fd = fopen(packfile, "rb");
 			if(fd == NULL) continue;
