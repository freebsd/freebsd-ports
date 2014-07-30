--- unix/vm-sound-pulse/sqUnixSoundPulseAudio.c.orig	2012-08-08 10:34:42 +0800
+++ unix/vm-sound-pulse/sqUnixSoundPulseAudio.c
@@ -995,10 +995,10 @@ DBGMSG("<sound_StartRecording()");
 static sqInt sound_StopRecording(void) {
 DBGMSG(">sound_StopRecording()");
 
-	if (!audioIn.open) return;
+	if (!audioIn.open) return false;
 	audioIn.open = false;
 	
-	if (NULL == audioIn.pa_conn) return;
+	if (NULL == audioIn.pa_conn) return false;
 	
 	ioThreadStall(&audioIn);
 
