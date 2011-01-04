--- src/runtime/DistributedPythonNode.cxx.orig	2010-11-08 15:29:37.000000000 +0600
+++ src/runtime/DistributedPythonNode.cxx	2010-11-08 15:29:44.000000000 +0600
@@ -17,6 +17,7 @@
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
 
+#include "PyStdout.hxx"
 #include "DistributedPythonNode.hxx"
 #include "RuntimeSALOME.hxx"
 #include "SalomeContainer.hxx"
@@ -24,7 +25,6 @@
 
 #include "PythonPorts.hxx"
 #include "YacsTrace.hxx"
-#include "PyStdout.hxx"
 
 using namespace YACS::ENGINE;
 using namespace std;
