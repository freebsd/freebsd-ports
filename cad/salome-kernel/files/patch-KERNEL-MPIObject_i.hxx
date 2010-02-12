--- src/MPIContainer/MPIObject_i.hxx.orig	2009-10-16 15:06:13.000000000 +0700
+++ src/MPIContainer/MPIObject_i.hxx	2009-10-16 15:06:22.000000000 +0700
@@ -26,6 +26,7 @@
 #ifndef _SALOME_POBJECT_I_H_
 #define _SALOME_POBJECT_I_H_ 
 
+#include <map>
 #include <mpi.h>
 #include <string>
 #include <SALOMEconfig.h>
