--- src/Project.cpp.orig	Sat Jan  5 23:15:27 2002
+++ src/Project.cpp	Sun Dec 22 03:36:25 2002
@@ -25,7 +25,7 @@
 #include "GObject.h"
 #include "AppInfo.h"
 
-Project::Project(QObject* parent=NULL, const char* name=0)
+Project::Project(QObject* parent, const char* name)
 	: QObject(parent, name)
 {
   main = (MainWindow*)parent;
