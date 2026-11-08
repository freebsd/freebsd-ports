https://github.com/nzeemin/ukncbtl-qt/issues/9

--- qscreen.cpp.orig	2026-06-25 15:25:21 UTC
+++ qscreen.cpp
@@ -473,6 +473,8 @@ void QEmulatorScreen::keyReleaseEvent(QKeyEvent *event
 
 void QEmulatorScreen::keyReleaseEvent(QKeyEvent *event)
 {
+    if (event->isAutoRepeat()) return;
+
     unsigned char ukncscan = TranslateQtKeyToUkncKey(event->key());
     if (ukncscan == 0) return;
 
