--- src/gsiqt/qt5/QtUiTools/QtUiTools.pro.orig	2021-08-28 16:35:24 UTC
+++ src/gsiqt/qt5/QtUiTools/QtUiTools.pro
@@ -10,7 +10,7 @@ DEFINES += MAKE_GSI_QTUITOOLS_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic -lklayout_QtCore
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtCore.so
 
 SOURCES += \
 
