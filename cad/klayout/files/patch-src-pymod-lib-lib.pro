--- src/pymod/lib/lib.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pymod/lib/lib.pro
@@ -10,5 +10,5 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_lib
+LIBS += $$DESTDIR/../libklayout_lib.so
 
