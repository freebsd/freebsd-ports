--- Source/C/NCSnet/NCScnet3/NCSProxy.cpp.orig	2009-04-05 21:38:54.000000000 +0400
+++ Source/C/NCSnet/NCScnet3/NCSProxy.cpp	2013-12-12 15:30:11.000000000 +0100
@@ -43,6 +43,10 @@
 #include <stdio.h> // for cuserid
 #endif
 
+#ifdef FREEBSD
+#include <unistd.h>
+#endif
+
 /** Dialog to prompt for Username and Password.
  */
 bool NCSGetPasswordDlg( const char *pszSite, const char *pszRealm, string &sUsername, string &sPassword, bool &bRememberAuth );
@@ -639,7 +643,7 @@
 		return(NCSStrDup(szNameBuf));
 	}
 #elif defined(POSIX)
-#if defined( LINUX ) || defined( MACOSX )
+#if defined( LINUX ) || defined( MACOSX ) || defined (FREEBSD)
 	fprintf(stderr, "CNCSProxy::GetCurrentUserName() using loging instead of cuserid. FIXME\n");
 	return(NCSStrDup(getlogin()));
 #else
