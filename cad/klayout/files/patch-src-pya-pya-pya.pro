--- src/pya/pya/pya.pro.orig	2021-08-28 17:01:08 UTC
+++ src/pya/pya/pya.pro
@@ -35,7 +35,7 @@ HEADERS += \
 
 INCLUDEPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC
 DEPENDPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC
-LIBS += "$$PYTHONLIBFILE" -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += "$$PYTHONLIBFILE" $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
 !msvc {
   # Python is somewhat sloppy and relies on the compiler initializing fields
