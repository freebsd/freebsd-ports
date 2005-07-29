--- sfx2/source/appl/officeacceptthread.cxx.orig	Sat Jul 20 22:56:19 2002
+++ sfx2/source/appl/officeacceptthread.cxx	Sat Jul 20 22:56:54 2002
@@ -123,13 +123,13 @@
 			sal_Bool static isProcessRunning( ::vos::OProcess::TProcessInfo& aProcessInfo )
 			{
 				int nRet;
-#if defined (SOLARIS) || defined (IRIX)
+#if defined (SOLARIS) || defined (IRIX) || defined (FREEBSD) || defined (NETBSD)
 				int status;
 				nRet = waitpid(aProcessInfo.Ident, &status,WNOHANG);
 #elif defined(LINUX)
 				nRet = kill(aProcessInfo.Ident, 0);
 #endif
-#if defined (LINUX) || defined (SOLARIS) || defined (IRIX)
+#if defined (LINUX) || defined (SOLARIS) || defined (IRIX) || defined (FREEBSD) || defined (NETBSD)
 				if ( nRet == 0 )
 					return sal_True; // process is running
 				if ( nRet < 0 )
