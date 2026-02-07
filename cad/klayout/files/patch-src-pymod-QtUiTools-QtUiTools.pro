--- src/pymod/QtUiTools/QtUiTools.pro.orig	2021-08-28 19:59:47 UTC
+++ src/pymod/QtUiTools/QtUiTools.pro
@@ -8,6 +8,6 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtUiTools
-LIBS += -lklayout_QtCore
+LIBS += $$LIBDIR/libklayout_QtUiTools.so
+LIBS += $$LIBDIR/libklayout_QtCore.so
 
