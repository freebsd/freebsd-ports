--- cfheader.h.orig	2014-02-21 15:42:52.379291286 -0500
+++ cfheader.h	2014-02-21 16:02:51.918208148 -0500
@@ -15,10 +15,12 @@
 #define __CFHEADER_H__
 
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "cftypes.h"
 #include "bstring.h"
 
+using std::ifstream;
+using std::ofstream;
 ////////////////////////////////////////////////////////////////////////////////
 
 // This class contains all the fixed fields always preset in a cabinet header
