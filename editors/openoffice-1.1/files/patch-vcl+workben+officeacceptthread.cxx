--- ../vcl/workben/officeacceptthread.cxx.orig	Tue Jun  3 11:27:35 2003
+++ ../vcl/workben/officeacceptthread.cxx	Tue Jun  3 11:27:38 2003
@@ -122,10 +122,10 @@
 			sal_Bool static isProcessRunning( ::vos::OProcess::TProcessInfo& aProcessInfo )
 			{
 				int nRet;
-#if defined (SOLARIS)
+#if defined (SOLARIS) || defined (FREEBSD)
 				int status;
 				nRet = waitpid(aProcessInfo.Ident, &status,WNOHANG);
-#elif defined(LINUX) || defined (FREEBSD)
+#elif defined(LINUX)
 				nRet = kill(aProcessInfo.Ident, 0);
 #endif
 #if defined (UNX)
