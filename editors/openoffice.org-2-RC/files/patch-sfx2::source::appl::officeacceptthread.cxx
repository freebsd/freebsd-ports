--- ../sfx2/source/appl/officeacceptthread.cxx.orig	Thu Oct 11 15:39:58 2001
+++ ../sfx2/source/appl/officeacceptthread.cxx	Fri Oct 18 23:35:14 2002
@@ -126,7 +126,7 @@
 #if defined (SOLARIS)
 				int status;
 				nRet = waitpid(aProcessInfo.Ident, &status,WNOHANG);
-#elif defined(LINUX)
+#elif defined(LINUX) || defined (FREEBSD)
 				nRet = kill(aProcessInfo.Ident, 0);
 #endif
 #if defined (UNX)
