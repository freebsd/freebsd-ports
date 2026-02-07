--- src/gsiqt/qt5/QtWidgets/QtWidgets.pro.orig	2021-08-28 16:30:52 UTC
+++ src/gsiqt/qt5/QtWidgets/QtWidgets.pro
@@ -10,13 +10,13 @@ DEFINES += MAKE_GSI_QTWIDGETS_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 # because QPainter is used as base class for QStylePainter, we need this:
-LIBS += -lklayout_QtGui
+LIBS += $$DESTDIR/libklayout_QtGui.so
 
 # because QObject is the base class of some classes we need this
-LIBS += -lklayout_QtCore
+LIBS += $$DESTDIR/libklayout_QtCore.so
 
 SOURCES += \
   gsiDeclQtWidgetsAdd.cc
