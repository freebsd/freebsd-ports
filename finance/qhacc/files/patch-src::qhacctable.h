--- src/qhacctable.h.orig	Sun Nov 24 19:22:27 2002
+++ src/qhacctable.h	Sun Nov 24 19:26:03 2002
@@ -26,9 +26,10 @@
 #include <qstring.h>
 #include <qdatetime.h>
 
-class QFile;
+#include <fstream>
+using std::ostream;
 
-class ostream;
+class QFile;
 
 class QHaccTableIndex;
 
