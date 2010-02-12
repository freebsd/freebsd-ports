--- src/runtime/SalomeOptimizerLoop.cxx.orig	2009-12-20 00:17:21.000000000 +0600
+++ src/runtime/SalomeOptimizerLoop.cxx	2009-12-20 00:16:25.000000000 +0600
@@ -16,10 +16,10 @@
 //
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
+#include "PyStdout.hxx"
 #include "SalomeOptimizerLoop.hxx"
 #include <Python.h>
 #include "TypeCode.hxx"
-#include "PyStdout.hxx"
 
 //#define _DEVDEBUG_
 #include "YacsTrace.hxx"
