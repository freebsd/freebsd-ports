--- src/LifeCycleCORBA/TestContainerManager.cxx.orig	2009-05-28 22:07:55.000000000 +0700
+++ src/LifeCycleCORBA/TestContainerManager.cxx	2009-07-10 12:47:50.000000000 +0700
@@ -29,6 +29,7 @@
 #include <iostream>
 #ifndef WNT
 #include <unistd.h>
+#include <libgen.h>
 #endif
 #include <SALOMEconfig.h>
 #include "SALOME_NamingService.hxx"
