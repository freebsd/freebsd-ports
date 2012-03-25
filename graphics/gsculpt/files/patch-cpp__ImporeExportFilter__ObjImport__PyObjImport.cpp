--- cpp/ImportExportFilter/ObjImport/PyObjImport.cpp.orig	2009-06-22 04:58:54.000000000 +0900
+++ cpp/ImportExportFilter/ObjImport/PyObjImport.cpp	2012-03-06 23:06:16.000000000 +0900
@@ -8,6 +8,8 @@
 #ifndef PYOBJIMPORT_CPP__
 #define PYOBJIMPORT_CPP__
 
+#include <Python.h>
+
 #include <string>
 
 #include <boost/python.hpp>
