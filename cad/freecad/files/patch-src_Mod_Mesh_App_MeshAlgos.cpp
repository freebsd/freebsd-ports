--- ./src/Mod/Mesh/App/MeshAlgos.cpp.orig	Sat Feb 24 11:34:07 2007
+++ ./src/Mod/Mesh/App/MeshAlgos.cpp	Sun Apr 22 00:35:44 2007
@@ -23,7 +23,7 @@
 
 #include "PreCompiled.h"
 #ifndef _PreComp_
-# ifdef FC_OS_LINUX
+# if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	  include <unistd.h>
 # endif
 #endif
