--- src/pymod/QtGui/QtGui.pro.orig	2022-04-24 08:12:38 UTC
+++ src/pymod/QtGui/QtGui.pro
@@ -8,9 +8,9 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtGui -lklayout_QtCore
+LIBS += $$DESTDIR/../libklayout_QtGui.so $$DESTDIR/../libklayout_QtCore.so
 
 greaterThan(QT_MAJOR_VERSION, 4) {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$DESTDIR/../libklayout_QtWidgets.so
 }
 
