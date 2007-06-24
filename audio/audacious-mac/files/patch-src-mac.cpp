--- src/mac.cpp	Thu Feb  1 02:46:26 2007
+++ src/mac.cpp	Sun Jun 24 06:02:16 2007
@@ -146,7 +146,7 @@
 
 static int decompress_init(InputPlayback *playback)
 {
-    char *filename = playback->filename;
+    char *filename = url2filename(playback->filename);
 
     int nRetVal;
 
@@ -386,6 +386,7 @@
 
 void mac_get_song_info(char *filename, char **title, int *length)
 {
+    url2filename(filename);
     int nRetVal = 0;
 
     if (filename == NULL)
