--- src/pymod/QtCore/QtCore.pro.orig	2021-08-28 19:54:37 UTC
+++ src/pymod/QtCore/QtCore.pro
@@ -8,8 +8,8 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtCore -lklayout_QtGui
+LIBS += $$LIBDIR/libklayout_QtCore.so $$LIBDIR/libklayout_QtGui.so
 
 equals(HAVE_QT5, "1") {
-  LIBS += -lklayout_QtWidgets
+  LIBS += $$LIBDIR/libklayout_QtWidgets.so
 }
