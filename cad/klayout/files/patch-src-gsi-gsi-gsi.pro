--- src/gsi/gsi/gsi.pro.orig	2021-08-28 17:25:20 UTC
+++ src/gsi/gsi/gsi.pro
@@ -51,5 +51,5 @@ SOURCES += gsiDeclTl.cc 
 
 INCLUDEPATH += $$TL_INC
 DEPENDPATH += $$TL_INC
-LIBS += -L$$DESTDIR -lklayout_tl
+LIBS += $$DESTDIR/libklayout_tl.so
 
