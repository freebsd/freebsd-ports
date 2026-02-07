--- src/common/ConfigManager.cpp.orig	2016-08-13 15:20:47 UTC
+++ src/common/ConfigManager.cpp
@@ -10,6 +10,7 @@ extern "C" {
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <cmath>
+#include <unistd.h>
 
 #include "../AutoBuild.h"
 #include "../version.h"
