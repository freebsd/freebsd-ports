--- ./platform/emulator/fdomn.cc.orig	Sat Nov 23 17:04:46 2002
+++ ./platform/emulator/fdomn.cc	Sat Sep  3 18:46:09 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2002/11/23 22:04:46 $ by $Author: duchier $
- *    $Revision: 1.139 $
+ *    $Date: 2005/06/11 18:06:36 $ by $Author: duchier $
+ *    $Revision: 1.139.10.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -191,12 +191,12 @@
 
 inline
 int FDIntervals::findMinElem(void) {
-  return high ? i_arr[0].left : 0;
+  return high ? i_arr[0].left : -1;
 }
 
 inline
 int FDIntervals::findMaxElem(void) {
-  return high ? i_arr[high - 1].right : 0;
+  return high ? i_arr[high - 1].right : -1;
 }
 
 inline
