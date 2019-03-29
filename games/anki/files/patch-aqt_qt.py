--- aqt/qt.py.orig	2019-03-09 22:22:42 UTC
+++ aqt/qt.py
@@ -14,6 +14,7 @@ from anki.utils import isWin, isMac
 from PyQt5.Qt import *
 # trigger explicit message in case of missing libraries
 # instead of silently failing to import
+from PyQt5.QtWebChannel import *
 from PyQt5.QtWebEngineWidgets import *
 try:
     from PyQt5 import sip
@@ -42,7 +43,7 @@ qtmajor = (QT_VERSION & 0xff0000) >> 16
 qtminor = (QT_VERSION & 0x00ff00) >> 8
 qtpoint = QT_VERSION & 0xff
 
-if qtmajor != 5 or qtminor < 9 or qtminor == 10:
+if qtmajor != 5 or qtminor < 9 or qtminor <= 10:
     raise Exception("Anki does not support your Qt version.")
 
 # GUI code assumes python 3.6+
