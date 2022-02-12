--- common/ccPluginManager.cpp.orig	2020-09-08 09:36:07 UTC
+++ common/ccPluginManager.cpp
@@ -273,7 +273,7 @@ void ccPluginManager::loadFromPathsAndAddToList()
 		"*.dylib"
 #elif defined(Q_OS_WIN)
 		"*.dll"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 		"*.so"
 #else
 #error Need to specify the dynamic library extension for this OS.
