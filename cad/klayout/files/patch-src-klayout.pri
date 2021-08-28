--- src/klayout.pri.orig	2021-07-23 08:00:26 UTC
+++ src/klayout.pri
@@ -100,7 +100,9 @@ equals(HAVE_RUBY, "1") {
 }
 
 !isEmpty(RPATH) {
+  !equals($$basename(_PRO_FILE_), "unit_tests.pro") {
   QMAKE_RPATHDIR += $$RPATH
+  }
 }
 
 !isEmpty(BITS_PATH) {
