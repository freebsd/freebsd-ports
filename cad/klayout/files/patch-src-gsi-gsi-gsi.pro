--- src/gsi/gsi/gsi.pro.orig	2022-12-22 22:17:08 UTC
+++ src/gsi/gsi/gsi.pro
@@ -53,5 +53,5 @@ SOURCES += \
 
 INCLUDEPATH += $$TL_INC
 DEPENDPATH += $$TL_INC
-LIBS += -L$$DESTDIR -lklayout_tl
+LIBS += $$DESTDIR/libklayout_tl.so
 
