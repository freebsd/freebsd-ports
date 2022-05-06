--- src/pymod/lib/lib.pro.orig	2022-04-24 08:12:38 UTC
+++ src/pymod/lib/lib.pro
@@ -9,5 +9,5 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_lib
+LIBS += $$DESTDIR/../libklayout_lib.so
 
