--- ./svnqt/client_modify.cpp.orig	2008-07-05 15:53:08.000000000 +0400
+++ ./svnqt/client_modify.cpp	2008-07-05 15:53:53.000000000 +0400
@@ -188,9 +188,7 @@
 #endif
 
     svn_error_t * error =
-#if (SVN_VER_MAJOR >= 1) && (SVN_VER_MINOR >= 5)
-      svn_client_commit4
-#elif (SVN_VER_MAJOR >= 1) && (SVN_VER_MINOR >= 3)
+#if (SVN_VER_MAJOR >= 1) && (SVN_VER_MINOR >= 3)
       svn_client_commit3
 #else
       svn_client_commit2
