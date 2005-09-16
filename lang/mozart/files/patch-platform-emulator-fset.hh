--- ./platform/emulator/fset.hh.orig	Sat Jan  6 13:29:09 2001
+++ ./platform/emulator/fset.hh	Sat Sep  3 18:46:09 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2001/01/06 18:29:09 $ by $Author: tmueller $
- *    $Revision: 1.33 $
+ *    $Date: 2005/05/31 16:19:45 $ by $Author: duchier $
+ *    $Revision: 1.33.18.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -37,6 +37,7 @@
 
 //-----------------------------------------------------------------------------
 
+class FSetConstraint;
 class FSetValue : public OZ_FSetValue {
 
 friend class FSetConstraint;
