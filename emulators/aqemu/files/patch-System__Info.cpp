--- System_Info.cpp.orig	2010-12-09 15:59:16.000000000 +0000
+++ System_Info.cpp
@@ -20,6 +20,7 @@
 **
 ****************************************************************************/
 
+#include <unistd.h>
 #include <QSettings>
 #include <QRegExp>
 #include <QProcess>
