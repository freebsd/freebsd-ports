Reset seek position for BGM with more than 128 tracks

--- source/gamelib/packfile.c.orig	2018-02-19 15:02:50 UTC
+++ source/gamelib/packfile.c
@@ -1408,7 +1408,7 @@ void packfile_music_read(fileliststruct *filelist, int
         getBasePath(packfile, filelist[i].filename, 1);
         if(stristr(packfile, ".pak"))
         {
-            memset(filelist[i].bgmTracks, 0, PACKFILE_PATH_MAX);
+            memset(filelist[i].bgmTracks, 0, sizeof(filelist[i].bgmTracks));
             filelist[i].nTracks = 0;
             fd = fopen(packfile, "rb");
             if(fd == NULL)
