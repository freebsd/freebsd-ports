--- src/MPIContainer/MPIObject_i.hxx.orig	2010-11-17 10:23:50.000000000 +0600
+++ src/MPIContainer/MPIObject_i.hxx	2010-11-17 10:24:06.000000000 +0600
@@ -27,6 +27,7 @@
 #ifndef _SALOME_POBJECT_I_H_
 #define _SALOME_POBJECT_I_H_ 
 
+#include <map>
 #include <mpi.h>
 #include <string>
 #include <SALOMEconfig.h>
