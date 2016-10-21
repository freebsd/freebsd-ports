--- src/audio/openal/openal_audio.cpp.orig	2016-09-04 17:31:41 UTC
+++ src/audio/openal/openal_audio.cpp
@@ -168,7 +168,8 @@ OpenALAudio::OpenALAudio()
 
 OpenALAudio::~OpenALAudio()
 {
-	this->deinit();
+	if (this->init_flag != 0)
+		this->deinit();
 }
 
 // Initialize the mid driver
