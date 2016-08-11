--- src/libUnicorn/UnicornCommon.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/libUnicorn/UnicornCommon.cpp
@@ -29,6 +29,10 @@
 #include <QCoreApplication>
 #include <QDir>
 
+#ifdef Q_OS_UNIX
+    #include <unistd.h>
+#endif
+
 #ifdef WIN32
     #include <windows.h>
     #include <shlobj.h>
