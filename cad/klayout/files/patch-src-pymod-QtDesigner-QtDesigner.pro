--- src/pymod/QtDesigner/QtDesigner.pro.orig	2021-08-28 19:56:24 UTC
+++ src/pymod/QtDesigner/QtDesigner.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtDesigner
+LIBS += $$LIBDIR/libklayout_QtDesigner.so
