--- application/MultiMC.cpp.orig	2017-12-18 00:19:43 UTC
+++ application/MultiMC.cpp
@@ -322,7 +322,7 @@ MultiMC::MultiMC(int &argc, char **argv)
 	// Set up paths
 	{
 		// Root path is used for updates.
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 		QDir foo(FS::PathCombine(binPath, ".."));
 		m_rootPath = foo.absolutePath();
 #elif defined(Q_OS_WIN32)
