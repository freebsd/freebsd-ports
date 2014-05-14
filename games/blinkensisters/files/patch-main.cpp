Game fails to load this file
--- main.cpp.orig	2008-12-06 23:51:54.000000000 +0300
+++ main.cpp	2014-05-11 20:09:10.346486193 +0400
@@ -446,11 +446,7 @@
 
 	// Display the Intro sequence
 #ifdef CAVAC_RELEASEMODE
-#ifdef HASOGGSUPPORT
-	playogg(configGetPath("startanim_video.ogg"),gScreen); /* play the standard ogg video instead of the BMF showVideo("startanim.bmf", true); */
-#else // HASOGGSUPPORT
 	showVideo("startanim.bmf", true, true);
-#endif // NO HASOGGSUPPORT
 #endif // CAVAC_RELEASEMODE
 	configStartupComplete();
 
