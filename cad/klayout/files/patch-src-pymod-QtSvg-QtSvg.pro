--- src/pymod/QtSvg/QtSvg.pro.orig	2021-08-28 19:59:24 UTC
+++ src/pymod/QtSvg/QtSvg.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtSvg
+LIBS += $$LIBDIR/libklayout_QtSvg.so
