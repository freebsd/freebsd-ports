--- daap.c.orig	Wed Jul 28 06:39:51 2004
+++ daap.c	Wed Jul 28 06:41:27 2004
@@ -456,6 +456,7 @@
         char time[11] = {0};
         char track[11] = {0};
         char year[11] = {0};
+        int minutes, seconds;
 
         if (selected_artist &&
                 strcasecmp(selected_artist, currentSongItems[i].songartist) != 0)
@@ -464,7 +465,6 @@
                 strcasecmp(selected_album, currentSongItems[i].songalbum) != 0)
             continue;
 
-        int minutes, seconds;
 
         seconds = (currentSongItems[i].songtime) / 1000;
         minutes = seconds / 60;
@@ -563,10 +563,10 @@
 char *get_song_display_str_withalloc(int id)
 {
     int songindex = findSongByID(id);
+    char *buf;
 
     if (!songindex) return NULL;
 
-    char *buf;
     buf = malloc(strlen(currentSongItems[songindex].songartist) + strlen(" - ")
                  + strlen(currentSongItems[songindex].itemname) + 1);
 
