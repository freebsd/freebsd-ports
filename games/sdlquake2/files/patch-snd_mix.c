--- ./snd_mix.c.orig	Thu May 19 17:56:13 2005
+++ ./snd_mix.c	Sun Feb 26 11:23:56 2006
@@ -168,8 +168,8 @@
 ===============================================================================
 */
 
-void __cdecl S_PaintChannelFrom8 (channel_t *ch, sfxcache_t *sc, int endtime, int offset);
-void __cdecl S_PaintChannelFrom16 (channel_t *ch, sfxcache_t *sc, int endtime, int offset);
+void S_PaintChannelFrom8 (channel_t *ch, sfxcache_t *sc, int endtime, int offset);
+void S_PaintChannelFrom16 (channel_t *ch, sfxcache_t *sc, int endtime, int offset);
 
 void S_PaintChannels(int endtime)
 {
@@ -349,7 +349,7 @@
 }
 
 
-void __cdecl S_PaintChannelFrom16 (channel_t *ch, sfxcache_t *sc, int count, int offset)
+void S_PaintChannelFrom16 (channel_t *ch, sfxcache_t *sc, int count, int offset)
 {
 	int data;
 	int left, right;
