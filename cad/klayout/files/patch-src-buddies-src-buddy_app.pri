--- src/buddies/src/buddy_app.pri.orig	2021-07-23 08:00:26 UTC
+++ src/buddies/src/buddy_app.pri
@@ -19,31 +19,31 @@ SOURCES = $$PWD/bd/main.cc
 
 INCLUDEPATH += $$BD_INC $$TL_INC $$GSI_INC
 DEPENDPATH += $$BD_INC $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_bd -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_lib -lklayout_rdb -lklayout_lym
+LIBS += $$DESTDIR/libklayout_bd.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_lib.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so
 
 INCLUDEPATH += $$RBA_INC
 DEPENDPATH += $$RBA_INC
 
 equals(HAVE_RUBY, "1") {
-  LIBS += -lklayout_rba
+  LIBS += $$DESTDIR/libklayout_rba.so
 } else {
-  LIBS += -lklayout_rbastub
+  LIBS += $$DESTDIR/libklayout_rbastub.so
 }
 
 INCLUDEPATH += $$PYA_INC
 DEPENDPATH += $$PYA_INC
 
 equals(HAVE_PYTHON, "1") {
-  LIBS += -lklayout_pya
+  LIBS += $$DESTDIR/libklayout_pya.so
 } else {
-  LIBS += -lklayout_pyastub
+  LIBS += $$DESTDIR/libklayout_pyastub.so
 }
 
 DEFINES += BD_TARGET=$$TARGET
 
 LIBS += $$RUBYLIBFILE
 
-if(mac|linux*) {
+if(mac|linux*|*bsd*) {
   LIBS += -ldl
 }
 
