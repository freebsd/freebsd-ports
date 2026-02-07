--- src/pya/pya/pya.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pya/pya/pya.pro
@@ -40,7 +40,7 @@ HEADERS += \
 
 INCLUDEPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC
 DEPENDPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC
-LIBS += "$$PYTHONLIBFILE" -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += "$$PYTHONLIBFILE" $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
 !msvc {
   # Python is somewhat sloppy and relies on the compiler initializing fields
