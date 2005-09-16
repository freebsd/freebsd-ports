--- ./platform/emulator/libdp/table.cc.orig	Mon Apr 28 08:32:28 2003
+++ ./platform/emulator/libdp/table.cc	Sat Sep  3 18:46:09 2005
@@ -9,8 +9,8 @@
  *    Per Brand, 1998
  * 
  *  Last change:
- *    $Date: 2003/04/28 12:32:28 $ by $Author: glynn $
- *    $Revision: 1.88 $
+ *    $Date: 2005/08/02 12:08:58 $ by $Author: glynn $
+ *    $Revision: 1.88.8.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -45,8 +45,8 @@
 ((po)->isTertiary() ? makeTaggedConst((po)->getTertiary()) : (po)->getRef())
 
 //
-template class GenDistEntryTable<BorrowEntry>;
 #include "hashtblDefs.cc"
+template class GenDistEntryTable<BorrowEntry>;
 
 
 OwnerTable *ownerTable;
