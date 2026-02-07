--- src/libs/musicplayer/OpenALMusicPlayer.cpp.orig	2018-02-11 19:14:32 UTC
+++ src/libs/musicplayer/OpenALMusicPlayer.cpp
@@ -161,7 +161,7 @@ bool OpenALMusicPlayer::streamBuffer(ALuint buffer)
 {
 	char pcm[BUFFERSIZE];
 	int size = 0;
-	const char* error = '\0';
+	const char* error = nullptr;
 	
 	if (!stream->read(pcm, BUFFERSIZE, &size, &error)) {
 		GfError("OpenALMusicPlayer: Stream read error: %s\n", error);
@@ -268,4 +268,4 @@ bool OpenALMusicPlayer::startPlayback()
     alSourcePlay(source);
     
     return true;
-}
\ No newline at end of file
+}
