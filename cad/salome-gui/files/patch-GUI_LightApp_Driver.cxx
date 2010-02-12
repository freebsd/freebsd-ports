--- src/LightApp/LightApp_Driver.cxx.orig	2009-06-02 16:42:51.000000000 +0700
+++ src/LightApp/LightApp_Driver.cxx	2009-06-02 16:43:09.000000000 +0700
@@ -35,6 +35,8 @@
 #include <qfileinfo.h>
 #include <qdir.h>
 
+#include <fstream>
+
 #ifdef WIN32
 #include <time.h>
 #endif
