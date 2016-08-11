--- app/client/Services/RadioService/RadioService.cpp.orig	2013-09-03 12:19:10 UTC
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
