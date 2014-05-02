--- common/edaappl.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ common/edaappl.cpp	2014-05-01 17:52:47.000000000 +0200
@@ -451,7 +451,7 @@
 
     // Linux and Unix
 #elif defined(__UNIX__)
-    m_BinDir = wxStandardPaths().GetExecutablePath();
+    m_BinDir = wxStandardPaths::Get().GetExecutablePath();
 #else
     m_BinDir = argv[0];
 #endif // __UNIX__
