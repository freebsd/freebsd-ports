--- ./kpythonpluginfactory/kpythonpluginfactory.cpp.orig	2011-05-20 22:33:41.000000000 +0200
+++ ./kpythonpluginfactory/kpythonpluginfactory.cpp	2011-09-01 16:43:57.371033306 +0200
@@ -18,6 +18,8 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <dlfcn.h>
+
 #include <QtCore/QCoreApplication>
 #include <QFileInfo>
 #include <QDir>
@@ -305,6 +307,8 @@
 // symbols global and available for later loaded libraries/module.
 QLibrary *LoadPythonLibrary()
 {
+    /* Promote this library (and thus libpython) to RTLD_GLOBAL) */
+    dlopen("kpythonpluginfactory.so", RTLD_NOLOAD | RTLD_GLOBAL);
     QLibrary *pythonLib = new QLibrary();
     pythonLib->setLoadHints(QLibrary::ExportExternalSymbolsHint);
     pythonLib->setFileName(LIB_PYTHON);
