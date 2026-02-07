--- src/pymod/QtCore/QtCore.pro.orig	2022-04-24 08:12:38 UTC
+++ src/pymod/QtCore/QtCore.pro
@@ -8,8 +8,8 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtCore -lklayout_QtGui
+LIBS += $$DESTDIR/../libklayout_QtCore.so $$DESTDIR/../libklayout_QtGui.so
 
 greaterThan(QT_MAJOR_VERSION, 4) {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$DESTDIR/../libklayout_QtWidgets.so
 }
