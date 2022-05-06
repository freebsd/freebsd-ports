--- src/pymod/QtXml/QtXml.pro.orig	2022-04-24 08:12:38 UTC
+++ src/pymod/QtXml/QtXml.pro
@@ -8,11 +8,11 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtCore -lklayout_QtXml
+LIBS += $$DESTDIR/../libklayout_QtCore.so $$DESTDIR/../libklayout_QtXml.so
 
 # Because of stupid dependency of QtCore on QtGui and this on QtWidgets:
-LIBS += -lklayout_QtGui
+LIBS += $$DESTDIR/../libklayout_QtGui.so
 
 greaterThan(QT_MAJOR_VERSION, 4) {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$DESTDIR/../libklayout_QtWidgets.so
 }
