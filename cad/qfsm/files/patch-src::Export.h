--- src/Export.h.orig	Sat Feb 14 21:06:52 2004
+++ src/Export.h	Tue Mar 16 23:45:39 2004
@@ -19,7 +19,8 @@
 #ifndef EXPORT_H
 #define EXPORT_H
 
-#include <fstream.h>
+#include <fstream>
+using namespace std;
 #include <qstring.h>
  
 class Machine;
