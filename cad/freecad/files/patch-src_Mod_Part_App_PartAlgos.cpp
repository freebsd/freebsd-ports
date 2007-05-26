--- ./src/Mod/Part/App/PartAlgos.cpp.orig	Sat Feb 24 11:33:05 2007
+++ ./src/Mod/Part/App/PartAlgos.cpp	Sun Apr 22 00:26:46 2007
@@ -23,7 +23,7 @@
 
 #include "PreCompiled.h"
 #ifndef _PreComp_
-# ifdef FC_OS_LINUX
+# if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	  include <unistd.h>
 # endif
 # include <BRep_Builder.hxx>
