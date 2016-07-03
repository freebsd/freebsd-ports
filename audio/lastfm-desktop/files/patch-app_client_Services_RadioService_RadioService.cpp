--- app/client/Services/RadioService/RadioService.cpp.orig	2016-06-16 20:32:08 UTC
+++ app/client/Services/RadioService/RadioService.cpp
@@ -307,7 +307,7 @@ RadioService::mute()
 void
 RadioService::onPhononStateChanged( Phonon::State newstate, Phonon::State oldstate )
 {
-    qDebug() << oldstate << " -> " << newstate;
+    qDebug() << (int)oldstate << " -> " << (int)newstate;
     if (m_mediaObject == 0) {
         qDebug() << "m_mediaObject is null!";
         return;
