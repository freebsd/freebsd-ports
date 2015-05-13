--- src/utils.cpp.orig	2010-05-17 03:38:35.000000000 +0400
+++ src/utils.cpp	2013-09-17 03:18:36.343226027 +0400
@@ -21,6 +21,7 @@
 #else
 	#include <dirent.h>
 	#include <sys/types.h>
+	#include <unistd.h>
 	#include <pwd.h>
 #endif
 
