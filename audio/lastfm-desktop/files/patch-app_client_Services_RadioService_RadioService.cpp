--- ./app/client/Services/RadioService/RadioService.cpp.orig	2014-08-29 11:45:14.000000000 +0200
+++ ./app/client/Services/RadioService/RadioService.cpp	2014-08-29 11:45:43.000000000 +0200
@@ -309,7 +309,7 @@
 void
 RadioService::onPhononStateChanged( Phonon::State newstate, Phonon::State oldstate )
 {
-    qDebug() << oldstate << " -> " << newstate;
+    //qDebug() << oldstate << " -> " << newstate;
     if (m_mediaObject == 0) {
         qDebug() << "m_mediaObject is null!";
         return;
