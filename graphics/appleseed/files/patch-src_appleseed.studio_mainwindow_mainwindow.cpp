--- src/appleseed.studio/mainwindow/mainwindow.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed.studio/mainwindow/mainwindow.cpp
@@ -27,6 +27,9 @@
 // THE SOFTWARE.
 //
 
+// XXX: must be included before Qt headers because of `slot' redefine
+#include "mainwindow/pythonconsole/pythonconsolewidget.h"
+
 // Interface header.
 #include "mainwindow.h"
 
@@ -39,7 +42,6 @@
 #include "mainwindow/minimizebutton.h"
 #include "mainwindow/project/attributeeditor.h"
 #include "mainwindow/project/projectexplorer.h"
-#include "mainwindow/pythonconsole/pythonconsolewidget.h"
 #include "mainwindow/rendering/lightpathstab.h"
 #include "mainwindow/rendering/materialdrophandler.h"
 #include "mainwindow/rendering/renderwidget.h"
@@ -684,7 +686,7 @@ void MainWindow::build_log_panel()
 
 void MainWindow::build_python_console_panel()
 {
-    char* python_home = Py_GetPythonHome();
+    char* python_home = Py_EncodeLocale(Py_GetPythonHome(), nullptr);
     if (python_home == nullptr)
         RENDERER_LOG_INFO("Python home not set.");
     else RENDERER_LOG_INFO("Python home set to %s.", python_home);
