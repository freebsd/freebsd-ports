--- common/ccPluginManager.cpp.orig	2019-01-06 17:02:13.000000000 -0500
+++ common/ccPluginManager.cpp	2019-01-07 14:12:33.433157000 -0500
@@ -177,7 +177,7 @@
 		"*.dylib"
 #elif defined(Q_OS_WIN)
 		"*.dll"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 		"*.so"
 #else
 #error Need to specify the dynamic library extension for this OS.
