--- sd_oss.c.orig	Mon Mar 19 09:00:29 2001
+++ sd_oss.c	Tue Sep 14 17:26:13 2004
@@ -39,7 +39,8 @@
 
 boolean AdLibPresent, SoundBlasterPresent;
 	
-SDMode SoundMode, MusicMode;
+SDMode SoundMode;
+SMMode MusicMode;
 SDSMode DigiMode;
 
 static volatile boolean sqActive;
