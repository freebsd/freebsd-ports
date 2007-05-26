--- ./src/Main/MainPy.cpp.orig	Mon Feb 26 10:36:38 2007
+++ ./src/Main/MainPy.cpp	Sun Apr 22 00:25:41 2007
@@ -28,7 +28,7 @@
 # include <sstream>
 #endif
 
-#ifdef FC_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	include <unistd.h>
 #endif
 
@@ -71,7 +71,7 @@
     
     return TRUE;
 }
-#elif defined(FC_OS_LINUX)
+#elif defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 # ifndef GNU_SOURCE
 #   define GNU_SOURCE
 # endif
@@ -109,7 +109,7 @@
 
 #if defined(FC_OS_WIN32)
   strcpy(argv[0],App::Application::Config()["HomePath"].c_str());
-#elif defined(FC_OS_LINUX)
+#elif defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
   // get whole path of the library
   Dl_info info;
   int ret = dladdr((void*)initFreeCAD, &info);
