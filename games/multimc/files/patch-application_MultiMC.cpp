--- application/MultiMC.cpp.orig	2019-03-08 00:50:32 UTC
+++ application/MultiMC.cpp
@@ -324,7 +324,7 @@ MultiMC::MultiMC(int &argc, char **argv) : QApplicatio
     // Set up paths
     {
         // Root path is used for updates.
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         QDir foo(FS::PathCombine(binPath, ".."));
         m_rootPath = foo.absolutePath();
 #elif defined(Q_OS_WIN32)
