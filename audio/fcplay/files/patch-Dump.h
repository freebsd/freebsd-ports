--- Dump.h.orig	Mon Mar  3 22:47:00 1997
+++ Dump.h	Tue Jun  6 20:05:48 2006
@@ -2,8 +2,9 @@
 #define DUMP_H
 
 
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
+using namespace std;
 
 #include "MyTypes.h"
 #include "SmartPtr.h"
