--- ./platform/emulator/gname.cc.orig	Fri Aug  2 16:20:44 2002
+++ ./platform/emulator/gname.cc	Sat Sep  3 18:46:09 2005
@@ -11,8 +11,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2002/08/02 20:20:44 $ by $Author: popow $
- *    $Revision: 1.12 $
+ *    $Date: 2005/05/31 20:36:05 $ by $Author: duchier $
+ *    $Revision: 1.12.12.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -33,8 +33,8 @@
 #include "board.hh"
 
 //
-template class GenDistEntryTable<GName>;
 #include "hashtblDefs.cc"
+template class GenDistEntryTable<GName>;
 
 //
 GNameTable gnameTable;
