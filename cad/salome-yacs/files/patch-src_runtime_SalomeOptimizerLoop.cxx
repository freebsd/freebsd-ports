--- src/runtime/SalomeOptimizerLoop.cxx.orig	2010-11-08 13:35:05.000000000 +0600
+++ src/runtime/SalomeOptimizerLoop.cxx	2010-11-08 13:35:25.000000000 +0600
@@ -17,10 +17,10 @@
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
 
+#include "PyStdout.hxx"
 #include "SalomeOptimizerLoop.hxx"
 #include <Python.h>
 #include "TypeCode.hxx"
-#include "PyStdout.hxx"
 
 //#define _DEVDEBUG_
 #include "YacsTrace.hxx"
