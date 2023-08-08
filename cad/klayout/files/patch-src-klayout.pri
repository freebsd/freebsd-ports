--- src/klayout.pri.orig	2022-12-22 22:17:08 UTC
+++ src/klayout.pri
@@ -113,7 +113,9 @@ equals(HAVE_RUBY, "1") {
 }
 
 !isEmpty(RPATH) {
+  !equals($$basename(_PRO_FILE_), "unit_tests.pro") {
   QMAKE_RPATHDIR += $$RPATH
+  }
 }
 
 !isEmpty(BITS_PATH) {
