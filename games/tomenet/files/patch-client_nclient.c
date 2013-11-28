--- client/nclient.c.orig	2013-11-10 05:48:24.000000000 -0500
+++ client/nclient.c	2013-11-28 09:08:59.000000000 -0500
@@ -4358,7 +4358,11 @@
 #endif
     }
 
+ #ifdef USE_SOUND_2010
+  #ifdef SOUND_SDL
 	if (ambient_fading) ambient_handle_fading();
+  #endif
+ #endif
 
 	/* Handle chat time-stamping too - C. Blue */
 	if (c_cfg.time_stamp_chat) {
