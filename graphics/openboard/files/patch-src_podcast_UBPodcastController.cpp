--- src/podcast/UBPodcastController.cpp.orig	2026-03-23 11:30:46 UTC
+++ src/podcast/UBPodcastController.cpp
@@ -64,7 +64,7 @@
 #elif defined(Q_OS_OSX)
     #include "ffmpeg/UBFFmpegVideoEncoder.h"
     #include "ffmpeg/UBMicrophoneInput.h"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     #include "ffmpeg/UBFFmpegVideoEncoder.h"
     #include "ffmpeg/UBMicrophoneInput.h"
 #endif
@@ -315,7 +315,7 @@ void UBPodcastController::start()
         mVideoEncoder = new UBWindowsMediaVideoEncoder(this);  //deleted on stop
 #elif defined(Q_OS_OSX)
         mVideoEncoder = new UBFFmpegVideoEncoder(this);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         mVideoEncoder = new UBFFmpegVideoEncoder(this);
 #endif
 
@@ -780,7 +780,7 @@ QStringList UBPodcastController::audioRecordingDevices
     devices = UBWaveRecorder::waveInDevices();
 #elif defined(Q_OS_OSX)
     devices = UBMicrophoneInput::availableDevicesNames();
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     devices = UBMicrophoneInput::availableDevicesNames();
 #endif
 
