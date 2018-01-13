--- src/System_Info.cpp.orig	2017-12-31 00:45:58 UTC
+++ src/System_Info.cpp
@@ -21,6 +21,7 @@
 **
 ****************************************************************************/
 
+#include <unistd.h>
 #include <QSettings>
 #include <QRegExp>
 #include <QProcess>
