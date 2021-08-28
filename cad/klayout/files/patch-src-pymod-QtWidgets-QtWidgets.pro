--- src/pymod/QtWidgets/QtWidgets.pro.orig	2021-08-28 20:00:23 UTC
+++ src/pymod/QtWidgets/QtWidgets.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtWidgets
+LIBS += $$LIBDIR/libklayout_QtWidgets.so
