--- jfsw_src_20051009/source/sounds.c.orig	2005-10-09 15:28:24.000000000 +0200
+++ jfsw_src_20051009/source/sounds.c	2005-10-10 15:02:08.000000000 +0200
@@ -392,6 +392,7 @@
     if (DemoMode)    
         return(MUSIC_Error);
     
+#ifdef WINDOWS
     if (SongPtr)    
         StopSong();
     
@@ -412,7 +413,16 @@
     //DSPRINTF(ds,"Playing song");
     //MONO_PRINT(ds);
 
-    return((int)MUSIC_PlaySong(SongPtr, loopflag));
+    return((int)MUSIC_PlaySong(SongPtr, loopflag));
+    
+#else
+    void PlayMusic(char *_filename);
+    if(MusicDevice < 0) return;
+
+     // FIXME: I need this to get the music volume initialized (not sure why) -- Jim Bentler
+    MUSIC_SetVolume( MusicVolume );
+    PlayMusic(song_file_name);
+#endif
     }
 
 VOID
