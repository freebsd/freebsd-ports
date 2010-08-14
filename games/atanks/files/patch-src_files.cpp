--- ./src/files.cpp.orig	2010-08-14 12:32:25.605447928 +0200
+++ ./src/files.cpp	2010-08-14 12:32:44.893731770 +0200
@@ -2,10 +2,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dirent.h>
-
-#ifdef MACOSX
 #include <sys/stat.h>
-#endif
 
 #include "player.h"
 #include "files.h"
