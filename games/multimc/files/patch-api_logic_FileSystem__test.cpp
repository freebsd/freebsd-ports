--- api/logic/FileSystem_test.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/FileSystem_test.cpp
@@ -119,7 +119,7 @@ slots:
 
 // this is only valid on linux
 // FIXME: implement on windows, OSX, then test.
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	void test_createShortcut_data()
 	{
 		QTest::addColumn<QString>("location");
@@ -134,7 +134,7 @@ slots:
 							  << (QStringList() << "arg1" << "arg2")
 							  << "asdf"
 							  << QString()
-						 #if defined(Q_OS_LINUX)
+						 #if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 							  << MULTIMC_GET_TEST_FILE("data/FileSystem-test_createShortcut-unix")
 						 #elif defined(Q_OS_WIN)
 							  << QByteArray()
