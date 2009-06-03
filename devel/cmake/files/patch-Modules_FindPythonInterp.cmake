--- ./Modules/FindPythonInterp.cmake.orig	2009-02-21 23:36:50.000000000 +0300
+++ ./Modules/FindPythonInterp.cmake	2009-03-20 13:20:18.000000000 +0300
@@ -7,7 +7,7 @@
 #
 
 FIND_PROGRAM(PYTHON_EXECUTABLE
-  NAMES python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0 python1.6 python1.5 python
+  NAMES python python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0 python1.6 python1.5
   PATHS
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.6\\InstallPath]
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.5\\InstallPath]
