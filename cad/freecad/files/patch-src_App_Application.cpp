--- ./src/App/Application.cpp.orig	Sat Feb 24 11:35:04 2007
+++ ./src/App/Application.cpp	Sun Apr 22 00:17:01 2007
@@ -29,7 +29,7 @@
 #ifndef _PreComp_
 # include <iostream>
 # include <sstream>
-# ifdef FC_OS_LINUX
+# if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 # include <time.h>
 # include <unistd.h>
 # endif
@@ -1157,7 +1157,7 @@
   // installed as a fallback solution.
   //
   // Default paths for the user depending on the platform
-#if defined(FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
   if(getenv("HOME") != 0)
     mConfig["UserHomePath"] = getenv("HOME");
 #elif defined(FC_OS_WIN32)
@@ -1199,7 +1199,7 @@
   }
 }
 
-#if defined (FC_OS_LINUX)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 std::string Application::FindHomePath(const char* sCall)
 {
   // We have three ways to start this application either use one of the both executables or
