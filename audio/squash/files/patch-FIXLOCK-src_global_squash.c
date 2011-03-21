--- ./src/global_squash.c.orig	2003-12-05 21:23:51.000000000 +0100
+++ ./src/global_squash.c	2011-03-21 17:21:19.000000000 +0100
@@ -143,7 +143,6 @@
             playlist_queue_song( song, state_info.raw_songs[state_info.current_song].position );
         }
         state_info.current_song++;
-        squash_unlock(state_info.lock);
         squash_wunlock(database_info.lock);
         squash_unlock(song_queue.lock);
         squash_unlock(state_info.lock);
