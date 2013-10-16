--- Source/Utilities/log.cpp.orig	2012-10-27 10:18:51.000000000 +0200
+++ Source/Utilities/log.cpp	2013-10-11 00:14:27.000000000 +0200
@@ -10,6 +10,7 @@
 #include "common.h"
 #include "Utilities/log.h"
 #include "Engine/hud.h"
+#include <unistd.h>
 
 /**\class Log
  * \brief Main logging facilities for the code base. */
