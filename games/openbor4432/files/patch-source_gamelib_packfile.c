Reset seek position for BGM with more than 64 tracks

--- source/gamelib/packfile.c.orig	2015-04-18 21:22:03 UTC
+++ source/gamelib/packfile.c
@@ -1399,7 +1399,7 @@ void packfile_music_read(fileliststruct 
         getBasePath(packfile, filelist[i].filename, 1);
         if(stristr(packfile, ".pak"))
         {
-            memset(filelist[i].bgmTracks, 0, 256);
+            memset(filelist[i].bgmTracks, 0, sizeof(filelist[i].bgmTracks));
             filelist[i].nTracks = 0;
             fd = fopen(packfile, "rb");
             if(fd == NULL)
