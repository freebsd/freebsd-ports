--- ../vcl/workben/officeacceptthread.cxx.orig	Wed Mar  5 20:25:36 2003
+++ ../vcl/workben/officeacceptthread.cxx	Wed Mar  5 20:26:03 2003
@@ -125,7 +125,7 @@
 #if defined (SOLARIS)
 				int status;
 				nRet = waitpid(aProcessInfo.Ident, &status,WNOHANG);
-#elif defined(LINUX)
+#elif defined(LINUX) || defined (FREEBSD)
 				nRet = kill(aProcessInfo.Ident, 0);
 #endif
 #if defined (UNX)
