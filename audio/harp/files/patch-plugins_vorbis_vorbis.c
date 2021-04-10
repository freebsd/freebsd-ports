--- plugins/vorbis/vorbis.c.orig	2021-04-10 21:47:11 UTC
+++ plugins/vorbis/vorbis.c
@@ -21,7 +21,7 @@
 
 #define VORB_CONTINUE (-50)
 
-struct vorbisHandles{
+static struct vorbisHandles{
 	OggVorbis_File *vf;
 	unsigned int *total;
 	int rate;
