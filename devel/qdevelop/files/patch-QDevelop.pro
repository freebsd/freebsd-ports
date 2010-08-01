--- ./QDevelop.pro.orig	2010-04-17 11:24:40.000000000 +0400
+++ ./QDevelop.pro	2010-08-01 18:22:09.489810565 +0400
@@ -146,6 +146,3 @@
  OBJECTS_DIR +=  build/o/win32
  CONFIG -=  debug_and_release
 }
-!exists(resources/translations/QDevelop_Russian.qm) {
- error(Please run \"lrelease QDevelop.pro\" before building the project)
-}
