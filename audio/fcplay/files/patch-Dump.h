--- Dump.h.orig	1997-03-03 21:47:00 UTC
+++ Dump.h
@@ -2,8 +2,9 @@
 #define DUMP_H
 
 
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
+using namespace std;
 
 #include "MyTypes.h"
 #include "SmartPtr.h"
