--- src/global_squash.c.orig	2003-12-05 20:23:51 UTC
+++ src/global_squash.c
@@ -143,7 +143,6 @@ void load_state() {
             playlist_queue_song( song, state_info.raw_songs[state_info.current_song].position );
         }
         state_info.current_song++;
-        squash_unlock(state_info.lock);
         squash_wunlock(database_info.lock);
         squash_unlock(song_queue.lock);
         squash_unlock(state_info.lock);
