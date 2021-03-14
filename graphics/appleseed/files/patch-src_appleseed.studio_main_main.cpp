--- src/appleseed.studio/main/main.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed.studio/main/main.cpp
@@ -29,8 +29,9 @@
 
 // appleseed.studio headers.
 #include "commandlinehandler.h"
-#include "mainwindow/mainwindow.h"
+// XXX: must be included before Qt headers because of `slot' redefine
 #include "python/pythoninterpreter.h"
+#include "mainwindow/mainwindow.h"
 #include "utility/miscellaneous.h"
 
 // appleseed.shared headers.
@@ -141,7 +142,7 @@ namespace
             bf::path python_path = bf::path(Application::get_root_path()) / "python27";
 #else
             // On Linux, Python's standard libraries are located in lib/python2.7/.
-            bf::path python_path = bf::path(Application::get_root_path());
+            bf::path python_path = bf::path(Application::get_root_path()) / "..";
 #endif
 
             if (bf::is_directory(python_path))
@@ -159,18 +160,18 @@ namespace
                     "will use Python installation expected to exist in %s.",
                     python_home);
 
-                Py_SetPythonHome(python_home);
+                Py_SetPythonHome(Py_DecodeLocale(python_home, nullptr));
             }
             else
             {
                 const string python_path_str = python_path.make_preferred().string();
 
                 QMessageBox msgbox;
-                msgbox.setWindowTitle("Python 2.7 Installation Not Found");
+                msgbox.setWindowTitle("Python Installation Not Found");
                 msgbox.setIcon(QMessageBox::Critical);
                 msgbox.setText(
                     QString(
-                        "No Python 2.7 installation could be found in %1 where appleseed.studio expects one "
+                        "No Python installation could be found in %1 where appleseed.studio expects one "
                         "to be, and the PYTHONHOME environment variable is not defined or is empty. "
                         "appleseed.studio may not work satisfactorily.").arg(QString::fromStdString(python_path_str)));
                 msgbox.setStandardButtons(QMessageBox::Ok);
