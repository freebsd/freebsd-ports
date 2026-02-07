--- src/pymod/QtNetwork/QtNetwork.pro.orig	2021-08-28 19:58:14 UTC
+++ src/pymod/QtNetwork/QtNetwork.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtNetwork
+LIBS += $$LIBDIR/libklayout_QtNetwork.so
