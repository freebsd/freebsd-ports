--- mainwindow.cpp.orig	Tue Sep 28 14:13:06 2004
+++ mainwindow.cpp	Sun Oct 17 23:49:36 2004
@@ -53,6 +53,8 @@
 #include "showtextdialog.h"
 #include "process.h"
 
+#include <unistd.h>
+
 extern TextEditor *textEditor;
 extern Main *mainWindow;
 extern int statusbarTime;
