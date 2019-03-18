--- api/logic/FileSystem_test.cpp.orig	2019-03-07 17:32:17 UTC
+++ api/logic/FileSystem_test.cpp
@@ -119,7 +119,7 @@ slots:
 
 // this is only valid on linux
 // FIXME: implement on windows, OSX, then test.
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     void test_createShortcut_data()
     {
         QTest::addColumn<QString>("location");
