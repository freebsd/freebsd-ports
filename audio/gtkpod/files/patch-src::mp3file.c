--- src/mp3file.c.orig	Thu Jan 22 19:20:45 2004
+++ src/mp3file.c	Thu Jan 22 19:21:41 2004
@@ -1296,6 +1296,7 @@
 {
     Track *track = NULL;
     File_Tag filetag;
+    mp3info *mp3info;
 
     track = g_malloc0 (sizeof (Track));
 
@@ -1370,7 +1371,7 @@
     }
 
     /* Get additional info (play time and bitrate */
-    mp3info *mp3info = mp3file_get_info (name);
+    mp3info = mp3file_get_info (name);
     if (mp3info)
     {
 	track->tracklen = mp3info->milliseconds;
