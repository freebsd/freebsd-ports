--- ./src/global_squash.c~	Fri Dec  5 21:23:51 2003
+++ ./src/global_squash.c	Thu Feb 26 18:57:02 2004
@@ -143,7 +143,6 @@
             playlist_queue_song( song, state_info.raw_songs[state_info.current_song].position );
         }
         state_info.current_song++;
-        squash_unlock(state_info.lock);
         squash_wunlock(database_info.lock);
         squash_unlock(song_queue.lock);
         squash_unlock(state_info.lock);
