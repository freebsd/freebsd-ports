--- src/seqdisp.c	2006/08/27 19:09:35	298
+++ src/seqdisp.c	2006/08/29 19:57:34	304
@@ -384,13 +384,14 @@
 //full screenvideo functions
 BOOL seq_StartFullScreenVideo(char* videoName, char* audioName)
 {
-	bHoldSeqForAudio = FALSE;
-
 #ifdef DUMMY_VIDEO
 	debug( LOG_VIDEO, "seq_StartFullScreenVideo: Refusing to play video! (Not a bug)" );
-	return FALSE;
+	// FIXME We probably should call something like eventFireCallbackTrigger((TRIGGER_TYPE)CALL_VIDEO_QUIT); here!
+	return TRUE;
 #endif
 
+	bHoldSeqForAudio = FALSE;
+
 	frameSkip = 1;
 	switch(war_GetSeqMode())
 	{


