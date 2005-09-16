--- ./platform/emulator/libfd/fdaux.cc.orig	Thu Oct 17 09:01:44 2002
+++ ./platform/emulator/libfd/fdaux.cc	Sat Sep  3 18:46:08 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2002/10/17 13:01:44 $ by $Author: popow $
- *    $Revision: 1.12 $
+ *    $Date: 2005/01/30 10:42:35 $ by $Author: glynn $
+ *    $Revision: 1.12.10.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -28,8 +28,8 @@
 
 #include "fdaux.hh"
 
-template _OZ_ParamIterator<OZ_Return>;
-template PropagatorController_V_V;
+template class _OZ_ParamIterator<OZ_Return>;
+template class _PropagatorController_V_V<OZ_Return,OZ_FDIntVar,PROCEED,FAILED,SLEEP>;
 
 //-----------------------------------------------------------------------------
 // convert vector to C++ arrays
