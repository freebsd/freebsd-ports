--- aqt/qt.py.orig	2019-03-09 22:22:42 UTC
+++ aqt/qt.py
@@ -42,7 +42,7 @@ qtmajor = (QT_VERSION & 0xff0000) >> 16
 qtminor = (QT_VERSION & 0x00ff00) >> 8
 qtpoint = QT_VERSION & 0xff
 
-if qtmajor != 5 or qtminor < 9 or qtminor == 10:
+if qtmajor != 5 or qtminor < 9 or qtminor <= 10:
     raise Exception("Anki does not support your Qt version.")
 
 # GUI code assumes python 3.6+
