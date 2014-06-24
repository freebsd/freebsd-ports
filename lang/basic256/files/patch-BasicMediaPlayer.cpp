--- BasicMediaPlayer.cpp.orig	2014-06-20 20:34:01.000000000 +0200
+++ BasicMediaPlayer.cpp	2014-06-20 20:34:34.000000000 +0200
@@ -104,11 +104,11 @@
 }
 
 double BasicMediaPlayer::length() {
-	return QMediaPlayer::duration() / 1000.0d;
+	return QMediaPlayer::duration() / 1000.0;
 }
 
 double BasicMediaPlayer::position() {
-	return QMediaPlayer::position() / 1000.0d;
+	return QMediaPlayer::position() / 1000.0;
 }
 
 void BasicMediaPlayer::play() {
