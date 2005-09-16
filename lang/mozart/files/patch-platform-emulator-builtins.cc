--- ./platform/emulator/builtins.cc.orig	Wed Apr  7 21:11:20 2004
+++ ./platform/emulator/builtins.cc	Sat Sep  3 18:46:08 2005
@@ -20,8 +20,8 @@
  *    Christian Schulte, 1997
  * 
  *  Last change:
- *    $Date: 2004/04/08 01:11:20 $ by $Author: popow $
- *    $Revision: 1.778 $
+ *    $Date: 2005/02/15 13:33:16 $ by $Author: raph $
+ *    $Revision: 1.778.2.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -3132,6 +3132,8 @@
 
 #ifdef VAR_PORT
 
+// raph: This implementation is DEPRECATED.  The new builtin
+// BInewPort has now 0 inputs and 2 outputs.
 OZ_BI_define(BInewPort,1,1)
 {
   oz_declareIN(0,val);
@@ -3152,13 +3154,14 @@
 
 #else
 
-OZ_BI_define(BInewPort,1,1)
+OZ_BI_define(BInewPort,0,2)
 {
   OZ_Term strm = oz_newReadOnly(oz_currentBoard());
   OZ_Term port = oz_newPort(strm);
   
-  OZ_out(0)= port;
-  return oz_unify(OZ_in(0),strm);
+  OZ_out(0)= strm;
+  OZ_out(1)= port;
+  return PROCEED;
 } OZ_BI_end
 
 #define FAST_DOPORTSEND
