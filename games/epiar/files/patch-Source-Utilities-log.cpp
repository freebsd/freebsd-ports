--- Source/Utilities/log.cpp.orig	2012-10-27 08:18:51 UTC
+++ Source/Utilities/log.cpp
@@ -10,6 +10,7 @@
 #include "common.h"
 #include "Utilities/log.h"
 #include "Engine/hud.h"
+#include <unistd.h>
 
 /**\class Log
  * \brief Main logging facilities for the code base. */
