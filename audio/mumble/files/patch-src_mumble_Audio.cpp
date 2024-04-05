--- src/mumble/Audio.cpp.orig	2024-03-03 17:26:27 UTC
+++ src/mumble/Audio.cpp
@@ -43,7 +43,7 @@ void LoopUser::addFrame(const Mumble::Protocol::AudioD
 		QMutexLocker l(&qmLock);
 		bool restart = (qetLastFetch.elapsed() > 100);
 
-		long time = qetTicker.elapsed();
+		long long time = qetTicker.elapsed();
 
 		float r;
 		if (restart)
