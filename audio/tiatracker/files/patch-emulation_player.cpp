--- emulation/player.cpp.orig	2021-01-22 19:52:22 UTC
+++ emulation/player.cpp
@@ -67,6 +67,7 @@ void Player::startTimer() {
     // Replay loop
     while (doReplay) {
         double frameDuration = replayTvStandard == TiaSound::TvStandard::PAL ? 1000.0/50.0 : 1000.0/60.0;
+#if 0
         // Wait and allow events until shortly before next update
         while (elapsedTimer.elapsed() < lastReplayTime + (frameDuration - 10.0)) {
             QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
@@ -75,6 +76,12 @@ void Player::startTimer() {
         do {
             timestamp = elapsedTimer.elapsed();
         } while (timestamp < lastReplayTime + frameDuration);
+#endif
+        while ((timestamp = elapsedTimer.elapsed()) < lastReplayTime + frameDuration)
+        {
+            QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
+            QThread::msleep(1);
+        }
         // Do updates
         while (lastReplayTime < timestamp) {
             timerFired();
