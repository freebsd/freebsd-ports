--- svcore/plugin/DSSIPluginInstance.cpp.orig	2015-10-22 11:26:02 UTC
+++ svcore/plugin/DSSIPluginInstance.cpp
@@ -27,12 +27,6 @@
 
 #include <cstdlib>
 
-#ifndef Q_OS_WIN32
-#include <alloca.h>
-#else
-#include <memory.h>
-#endif
-
 //#define DEBUG_DSSI 1
 #define DEBUG_DSSI_PROCESS 1
 
