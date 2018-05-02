--- Engine/StandardPaths.cpp.orig	2017-08-13 15:26:35 UTC
+++ Engine/StandardPaths.cpp
@@ -46,7 +46,7 @@
 #endif
 #include <QtCore/QFileInfo>
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include <cerrno>
 #include <unistd.h>
 #include <sys/stat.h>
@@ -182,7 +182,7 @@ convertCharArray(const wchar_t *path)
     return QDir::fromNativeSeparators( QString::fromWCharArray(path) );
 }
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 //static
 QString
 resolveUserName(uint userId)
@@ -333,7 +333,7 @@ StandardPaths::writableLocation(StandardLocationEnum t
             
             return macLocation(type, kOnAppropriateDisk);
     }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     switch (type) {
     case eStandardLocationHome:
 
