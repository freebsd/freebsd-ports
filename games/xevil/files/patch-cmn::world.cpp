--- cmn/world.cpp.orig	Wed Jan 19 21:15:08 2000
+++ cmn/world.cpp	Sat Oct 25 21:45:40 2003
@@ -35,7 +35,8 @@
 #endif
 
 // Include Files.
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "utils.h"
 #include "coord.h"
