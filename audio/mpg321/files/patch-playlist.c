
$FreeBSD$

--- playlist.c.orig	Mon Sep 24 21:09:15 2001
+++ playlist.c	Mon Sep 24 21:09:34 2001
@@ -48,6 +48,7 @@
     pl->files_size = DEFAULT_PLAYLIST_SIZE;
     pl->numfiles = 0;
     pl->random_play = 0;
+    strcpy(pl->remote_file, "");
     
     return pl;
 }
