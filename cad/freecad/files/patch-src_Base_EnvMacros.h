--- ./src/Base/EnvMacros.h.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/EnvMacros.h	Sun Apr 22 00:06:11 2007
@@ -22,7 +22,7 @@
  *   Juergen Riegel 2002                                                   *
  ***************************************************************************/
 
-#if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 #	include <unistd.h>
 #	include <stdlib.h>
 #	include <string>
@@ -54,7 +54,7 @@
 
 void SetEnvironment(const char* sVar, const char* sVal)
 {
-#if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 	setenv(sVar, sVal, 1);
 //#elif defined (FC_OS_WIN32) // Seems not to work properly!
 //	SetEnvironmentVariable(sVar,sVal);
@@ -106,7 +106,7 @@
 	}
 }
 
-#if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 std::string FindHomePathUnix(const char* sCall)
 {
 	std::string argv = sCall;
@@ -486,7 +486,7 @@
 		sTempString3 += "dll";
 		sTempString3 += PATHSEP;
 		sTempString3 += "TKOpenGl.dll";
-#elif defined(FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#elif defined(FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 		sTempString3 += sLib;
 		sTempString3 += "lib";
 		sTempString3 += PATHSEP;
