--- src/pymod/lay/lay.pro.orig	2021-08-28 20:04:46 UTC
+++ src/pymod/lay/lay.pro
@@ -8,5 +8,5 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_lay
+LIBS += $$LIBDIR/libklayout_lay.so
 
