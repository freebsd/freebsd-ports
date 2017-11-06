--- server/scsynth/SC_CoreAudio.h.orig	2017-03-20 15:18:39 UTC
+++ server/scsynth/SC_CoreAudio.h
@@ -168,7 +168,7 @@ class SC_AudioDriver (protected)
 	EngineFifo mFromEngine, mToEngine;
 	EngineFifo mOscPacketsToEngine;
 	SC_SyncCondition mAudioSync;
-	thread mThread;
+	std::thread mThread;
 	bool mRunThreadFlag;
 	uint32 mSafetyOffset;
 	PriorityQueueT<SC_ScheduledEvent, 2048> mScheduler;
