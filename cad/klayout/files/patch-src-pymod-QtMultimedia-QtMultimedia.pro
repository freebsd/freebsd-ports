--- src/pymod/QtMultimedia/QtMultimedia.pro.orig	2021-08-28 19:57:41 UTC
+++ src/pymod/QtMultimedia/QtMultimedia.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtMultimedia -lklayout_QtNetwork
+LIBS += $$LIBDIR/libklayout_QtMultimedia.so $$LIBDIR/libklayout_QtNetwork.so
