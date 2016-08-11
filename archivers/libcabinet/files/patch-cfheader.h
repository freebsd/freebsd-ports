--- cfheader.h.orig	1999-10-24 06:13:29 UTC
+++ cfheader.h
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
