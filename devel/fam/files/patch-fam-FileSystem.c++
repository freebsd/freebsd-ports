diff -ruN fam/FileSystem.c++ fam/FileSystem.c++
--- fam/FileSystem.c++	Mon Apr 29 02:26:54 2002
+++ fam/FileSystem.c++	Sat Jun  8 16:31:07 2002
@@ -22,7 +22,7 @@
 
 #include "FileSystem.h"
 
-#include <mntent.h>
+#include "mntent.h"
 #include <string.h>
 
 #include "Event.h"
