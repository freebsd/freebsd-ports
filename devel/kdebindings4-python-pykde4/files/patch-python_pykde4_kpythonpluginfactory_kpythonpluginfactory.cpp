--- python/pykde4/kpythonpluginfactory/kpythonpluginfactory.cpp~	2009-10-31 16:30:02.000000000 +0200
+++ python/pykde4/kpythonpluginfactory/kpythonpluginfactory.cpp	2009-10-31 16:35:50.000000000 +0200
@@ -18,6 +18,8 @@
    Boston, MA 02111-1307, USA.
 */
 
+#include <dlfcn.h>
+
 #include <QtCore/QCoreApplication>
 #include <QFileInfo>
 #include <QDir>
@@ -295,6 +297,8 @@
 // symbols global and available for later loaded libraries/module.
 QLibrary *LoadPythonLibrary()
 {
+    /* Promote this library (and thus libpython) to RTLD_GLOBAL) */
+    dlopen("kpythonpluginfactory.so", RTLD_NOLOAD | RTLD_GLOBAL);
     QLibrary *pythonLib = new QLibrary();
     pythonLib->setLoadHints(QLibrary::ExportExternalSymbolsHint);
     pythonLib->setFileName(LIB_PYTHON);
