--- src/pymod/QtXmlPatterns/QtXmlPatterns.pro.orig	2021-08-28 20:01:33 UTC
+++ src/pymod/QtXmlPatterns/QtXmlPatterns.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtXmlPatterns -lklayout_QtNetwork
+LIBS += $$LIBDIR/libklayout_QtXmlPatterns.so $$LIBDIR/libklayout_QtNetwork.so
