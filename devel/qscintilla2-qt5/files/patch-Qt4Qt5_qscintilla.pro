Install the library as libqscintilla2-qt5.so.
The suffix is used to make it differ from libqscintilla2.so, which is the Qt4
version.
--- Qt4Qt5/qscintilla.pro.orig	2015-04-20 14:38:24 UTC
+++ Qt4Qt5/qscintilla.pro
@@ -23,7 +23,11 @@
 !win32:VERSION = 12.0.0
 
 TEMPLATE = lib
-TARGET = qscintilla2
+greaterThan(QT_MAJOR_VERSION, 4) {
+    TARGET = qscintilla2-qt$${QT_MAJOR_VERSION}
+} else {
+    TARGET = qscintilla2
+}
 CONFIG += qt warn_off release thread exceptions
 INCLUDEPATH += . ../include ../lexlib ../src
 
