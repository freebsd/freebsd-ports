--- plugins/import/FileSystem.cpp.orig	Fri Nov  1 00:55:42 2002
+++ plugins/import/FileSystem.cpp	Sun Apr 20 01:10:32 2003
@@ -1,8 +1,8 @@
+#include <sys/types.h>
 #include <sys/timeb.h>
-#include<qfiledialog.h>
+#include <qfiledialog.h>
 #include <tulip/TulipPlugin.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <dirent.h>
 
 struct FileSystem:public ImportModule
