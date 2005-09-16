--- ./platform/emulator/libfd/pel_fncts.hh.orig	Thu Oct 17 09:01:44 2002
+++ ./platform/emulator/libfd/pel_fncts.hh	Sat Sep  3 18:46:08 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  *
  *  Last change:
- *    $Date: 2002/10/17 13:01:44 $ by $Author: popow $
- *    $Revision: 1.11 $
+ *    $Date: 2005/01/30 10:40:51 $ by $Author: glynn $
+ *    $Revision: 1.11.10.1 $
  *
  *  This file is part of Mozart, an implementation
  *  of Oz 3:
@@ -46,8 +46,8 @@
   }
   //
   void print(ENGINE &e) {
-    // kost@ : this code does NOT insntatiate!
-    // I've simpliefied it (below);
+    // kost@ : this code does NOT instantiate!
+    // I've simplified it (below);
     /*
     printf("LessEqOffset x(%s,%d) + c(%d) <= ",
 	   (*(FDVAR *) e[_x])->toString(), _x, _c);
@@ -79,15 +79,15 @@
     : PEL_LessEqOffset<ENGINE,FDVAR,PFDVAR>(y, -c+1, x) {}
   //
   void print(ENGINE &e) {
-    // kost@ : this code does NOT insntatiate!
-    // I've simpliefied it (below);
+    // kost@ : this code does NOT instantiate!
+    // I've simplified it (below);
     /*
     printf("GreaterOffset x(%s,%d) + c(%d) > ",
 	   (*(FDVAR *) e[_y])->toString(), _y, -_c+1);
     printf("y(%s,%d)\n", (*(FDVAR *) e[_x])->toString(), _x);
     */
-    printf("GreaterOffset x(,%d) + c(%d) > ", _y, -_c+1);
-    printf("y(,%d)\n", _x);
+    printf("GreaterOffset x(,%d) + c(%d) > ", this->_y, -(this->_c)+1);
+    printf("y(,%d)\n", this->_x);
   }
 };
 
@@ -132,9 +132,9 @@
 pf_return_t PEL_LessEqOffset<ENGINE, FDVAR, PFDVAR>::propagate(PEL_Engine &e)
 {
   //
-  FDVAR &x = *(FDVAR *) e[_x];
-  int c = _c;
-  FDVAR &y = *(FDVAR *) e[_y];
+  FDVAR &x = *(FDVAR *) e[this->_x];
+  int c = this->_c;
+  FDVAR &y = *(FDVAR *) e[this->_y];
   //
   _PropagatorController_V_V<int,
     FDVAR,pf_entailed,pf_failed,pf_sleep> iter(x, y);
