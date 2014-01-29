--- src/libUnicorn/UnicornCommon.cpp.orig
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
