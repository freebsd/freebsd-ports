--- src/gsiqt/qt5/QtDesigner/QtDesigner.pro.orig	2021-08-28 17:27:01 UTC
+++ src/gsiqt/qt5/QtDesigner/QtDesigner.pro
@@ -10,7 +10,7 @@ DEFINES += MAKE_GSI_QTDESIGNER_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 SOURCES += \
 
