--- ./src/FileManager.cpp.orig	Sun Jun 10 01:55:51 2007
+++ ./src/FileManager.cpp	Sun Jun 10 01:56:13 2007
@@ -20,10 +20,12 @@
 // gimmage: FileManager.cpp
 #include "FileManager.h"
 #include "defines.h"
+#define get_current_dir_name() getcwd(NULL, PATH_MAX) 
 
 #include "../config.h"
 
 extern "C" {
+#include <libintl.h>
 #include <string.h>
 #include <unistd.h>
 }
