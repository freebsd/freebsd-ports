--- src/pymod/QtXml/QtXml.pro.orig	2021-08-28 20:00:46 UTC
+++ src/pymod/QtXml/QtXml.pro
@@ -8,11 +8,11 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtCore -lklayout_QtXml
+LIBS += $$LIBDIR/libklayout_QtCore.so $$LIBDIR/libklayout_QtXml.so
 
 # Because of stupid dependency of QtCore on QtGui and this on QtWidgets:
-LIBS += -lklayout_QtGui
+LIBS += $$LIBDIR/libklayout_QtGui.so
 
 equals(HAVE_QT5, "1") {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$LIBDIR/libklayout_QtWidgets.so
 }
