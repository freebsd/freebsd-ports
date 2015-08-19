--- src/q4wine-gui/process.cpp.orig	2015-07-24 20:19:50 UTC
+++ src/q4wine-gui/process.cpp
@@ -16,6 +16,8 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <locale.h>
+
 #include "process.h"
 
 Process::Process (QStringList args, QString exec, QString dir, QString info, QString caption, bool showErr, QStringList env, QWidget * parent, Qt::WFlags f)
