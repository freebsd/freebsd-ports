--- src/client/snd_mix.c.orig	Wed Oct  9 03:54:25 2002
+++ src/client/snd_mix.c	Thu Jun 12 15:16:54 2003
@@ -30,7 +30,7 @@
 
 void S_WriteLinearBlastStereo16 (void);
 
-#if !((defined __linux__ || defined __FreeBSD__) && defined __i386__)
+#if !((defined __linux__ || defined __FreeBSD__) && defined __i386__) || defined C_ONLY
 #if	!id386
 
 void S_WriteLinearBlastStereo16 (void)
@@ -362,7 +362,7 @@
 }
 
 
-#if !((defined __linux__ || __FreeBSD__) && defined __i386__)
+#if !((defined __linux__ || __FreeBSD__) && defined __i386__) || defined C_ONLY
 #if	!id386
 
 void S_PaintChannelFrom8 (channel_t *ch, sfxcache_t *sc, int count, int offset)
