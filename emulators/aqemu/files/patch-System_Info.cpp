--- System_Info.cpp.orig	2011-07-26 19:34:58 UTC
+++ System_Info.cpp
@@ -20,6 +20,7 @@
 **
 ****************************************************************************/
 
+#include <unistd.h>
 #include <QSettings>
 #include <QRegExp>
 #include <QProcess>
