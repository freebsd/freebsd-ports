--- src/pymod/QtGui/QtGui.pro.orig	2021-07-23 08:00:26 UTC
+++ src/pymod/QtGui/QtGui.pro
@@ -8,9 +8,9 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtGui -lklayout_QtCore
+LIBS += $$LIBDIR/libklayout_QtGui.so $$LIBDIR/libklayout_QtCore.so
 
 equals(HAVE_QT5, "1") {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$LIBDIR/libklayout_QtWidgets.so
 }
 
