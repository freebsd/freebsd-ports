--- src/buddies/unit_tests/unit_tests.pro.orig	2021-07-23 08:00:26 UTC
+++ src/buddies/unit_tests/unit_tests.pro
@@ -27,4 +27,8 @@ SOURCES += \
 INCLUDEPATH += $$BD_INC $$DB_INC $$TL_INC $$GSI_INC $$RBA_INC
 DEPENDPATH += $$BD_INC $$DB_INC $$TL_INC $$GSI_INC $$RBA_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_bd -lklayout_db -lklayout_tl -lklayout_gsi -l$$RBA_LIB
+LIBS += $$DESTDIR_UT/libklayout_bd.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
+
+!isEmpty(RBA_LIB) {
+  LIBS += $$DESTDIR_UT/lib$${RBA_LIB}.so
+}
