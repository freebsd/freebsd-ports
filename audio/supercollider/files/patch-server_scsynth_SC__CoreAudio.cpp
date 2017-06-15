--- server/scsynth/SC_CoreAudio.cpp.orig	2017-03-20 15:18:39 UTC
+++ server/scsynth/SC_CoreAudio.cpp
@@ -131,7 +131,7 @@ void initializeScheduler()
 {
 	syncOSCOffsetWithTimeOfDay();
 
-	thread resyncThread(resyncThreadFunc);
+	std::thread resyncThread(resyncThreadFunc);
 	resyncThread.detach();
 }
 #endif // SC_AUDIO_API_COREAUDIO
@@ -449,7 +449,7 @@ void SC_ScheduledEvent::Perform()
 bool SC_AudioDriver::Setup()
 {
 	mRunThreadFlag = true;
-	thread thread(std::bind(&SC_AudioDriver::RunThread, this));
+	std::thread thread(std::bind(&SC_AudioDriver::RunThread, this));
 	mThread = std::move(thread);
 
 	int numSamples;
