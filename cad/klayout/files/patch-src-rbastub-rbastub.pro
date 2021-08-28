--- src/rbastub/rbastub.pro.orig	2021-08-28 16:09:14 UTC
+++ src/rbastub/rbastub.pro
@@ -12,5 +12,5 @@ SOURCES = rba.cc
 
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
   
