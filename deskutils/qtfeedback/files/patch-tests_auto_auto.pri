--- tests/auto/auto.pri.orig	2021-06-30 09:31:55 UTC
+++ tests/auto/auto.pri
@@ -1,4 +1,4 @@
 TEMPLATE = app
 CONFIG += console testcase
 
-qtAddLibrary(QtTest)
+QT += testlib
