--- src/loop.c	2006/08/26 15:50:47	289
+++ src/loop.c	2006/08/29 19:57:34	304
@@ -1085,7 +1085,7 @@
 	paused = FALSE;
 	video = FALSE;
 	gameTimeStart();
-//	pie_SetFogStatus(TRUE);
+	pie_SetFogStatus(TRUE);
 	cdAudio_Resume();
 	ASSERT( videoMode == 0,"loop_ClearVideoPlaybackMode: out of sync." );
 }


