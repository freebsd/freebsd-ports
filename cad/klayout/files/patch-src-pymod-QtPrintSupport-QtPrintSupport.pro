--- src/pymod/QtPrintSupport/QtPrintSupport.pro.orig	2021-08-28 19:59:00 UTC
+++ src/pymod/QtPrintSupport/QtPrintSupport.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtPrintSupport
+LIBS += $$LIBDIR/libklayout_QtPrintSupport.so
