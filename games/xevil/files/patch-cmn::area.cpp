--- cmn/area.cpp.orig	Wed Mar 19 10:04:22 2003
+++ cmn/area.cpp	Sat Oct 25 21:39:50 2003
@@ -34,7 +34,8 @@
 extern "C" {
 #include <limits.h> // For INT_MAX
 }
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include "utils.h"
 #include "coord.h"
 #include "area.h"
