--- src/Export.cpp.orig	Mon Dec 29 05:35:44 2003
+++ src/Export.cpp	Tue Mar 16 23:40:15 2004
@@ -17,7 +17,8 @@
 */
 
 
-#include <iostream.h>
+#include <iostream>
+using namespace std; 
 #include <qapplication.h>
 #include "Export.h"
 #include "Machine.h"
