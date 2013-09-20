--- src/lib/IniFile.cpp.orig	2013-09-18 16:05:10.000000000 +0200
+++ src/lib/IniFile.cpp	2013-09-18 16:05:50.000000000 +0200
@@ -8,6 +8,7 @@
 
 #include "IniFile.h"
 #include <algorithm>    //find() function
+#include <stdlib.h>
 #include <string>
 #include "File64.h"
 #include "FilePath.h"
