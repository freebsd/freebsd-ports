--- Source/C/NCSnet/NCScnet3/NCSProxy.cpp.orig	2009-04-05 21:38:54.000000000 +0400
+++ Source/C/NCSnet/NCScnet3/NCSProxy.cpp	2009-04-05 21:39:11.000000000 +0400
@@ -639,7 +639,7 @@
 		return(NCSStrDup(szNameBuf));
 	}
 #elif defined(POSIX)
-#if defined( LINUX ) || defined( MACOSX )
+#if defined( LINUX ) || defined( MACOSX ) || defined (FREEBSD)
 	fprintf(stderr, "CNCSProxy::GetCurrentUserName() using loging instead of cuserid. FIXME\n");
 	return(NCSStrDup(getlogin()));
 #else
