--- plugins/import/FileSystem.cpp.orig	Fri Jan 10 12:54:43 2003
+++ plugins/import/FileSystem.cpp	Fri Jan 10 12:56:18 2003
@@ -1,8 +1,8 @@
+#include <sys/types.h>
 #include <sys/timeb.h>
 #include<qfiledialog.h>
 #include "TulipPlugin.h"
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <dirent.h>
 
 struct FileSystem:public ImportModule
