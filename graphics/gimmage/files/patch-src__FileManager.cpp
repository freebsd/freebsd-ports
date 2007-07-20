--- ./src/FileManager.cpp.orig	2007-07-20 23:42:55.000000000 +0400
+++ ./src/FileManager.cpp	2007-07-20 23:43:03.000000000 +0400
@@ -23,6 +23,7 @@
 
 #include "FileManager.h"
 #include "defines.h"
+#define get_current_dir_name() getcwd(NULL, PATH_MAX)
 
 #include "../config.h"
 
