--- src/pyastub/pyastub.pro.orig	2021-08-28 16:58:33 UTC
+++ src/pyastub/pyastub.pro
@@ -10,7 +10,7 @@ SOURCES = pya.cc 
 
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
 HEADERS += \
     pyaCommon.h \
