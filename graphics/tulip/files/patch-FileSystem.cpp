--- plugins/import/FileSystem.cpp.orig	Sat Dec  7 00:39:53 2002
+++ plugins/import/FileSystem.cpp	Mon May 26 01:24:45 2003
@@ -1,8 +1,8 @@
+#include <sys/types.h>
 #include <sys/timeb.h>
 #include <qfiledialog.h>
 #include <tulip/TulipPlugin.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <dirent.h>
 
 using namespace std;
