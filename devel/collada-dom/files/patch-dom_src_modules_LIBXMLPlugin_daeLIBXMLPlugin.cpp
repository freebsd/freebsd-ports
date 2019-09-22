--- dom/src/modules/LIBXMLPlugin/daeLIBXMLPlugin.cpp.orig	2019-05-09 19:36:39 UTC
+++ dom/src/modules/LIBXMLPlugin/daeLIBXMLPlugin.cpp
@@ -32,7 +32,7 @@
 #include <iomanip>
 using namespace std;
 
-#include <zip.h> // for saving compressed files
+#include <minizip/zip.h> // for saving compressed files
 #ifdef _WIN32
 #include <iowin32.h>
 #else
