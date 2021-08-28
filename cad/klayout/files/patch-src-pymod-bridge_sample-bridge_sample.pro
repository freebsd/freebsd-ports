--- src/pymod/bridge_sample/bridge_sample.pro.orig	2021-08-28 20:02:06 UTC
+++ src/pymod/bridge_sample/bridge_sample.pro
@@ -62,12 +62,12 @@ equals(HAVE_QT, "0") {
 }
 INCLUDEPATH += "$$PYTHONINCLUDE" $$INC/tl/tl $$INC/pya/pya $$INC/gsi/gsi
 DEPENDPATH += "$$PYTHONINCLUDE" $$INC/tl/tl $$INC/pya/pya $$INC/gsi/gsi
-LIBS += "$$PYTHONLIBFILE" -L$$LIBDIR -lklayout_tl -lklayout_pya -lklayout_gsi
+LIBS += "$$PYTHONLIBFILE" $$LIBDIR/libklayout_tl.so $$LIBDIR/libklayout_pya.so $$LIBDIR/libklayout_gsi.so
 
 # Also include DB as this is our sample
 INCLUDEPATH += $$INC/db/db
 DEPENDPATH += $$INC/db/db
-LIBS += -L$$LIBDIR -lklayout_db
+LIBS += $$LIBDIR/libklayout_db.so
 
 # Pull in RPATH
 !isEmpty(RPATH) {
