--- ./platform/emulator/libdp/dpResource.cc.orig	Mon May 24 08:49:09 2004
+++ ./platform/emulator/libdp/dpResource.cc	Sat Sep  3 18:46:09 2005
@@ -10,8 +10,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2004/05/24 12:49:09 $ by $Author: popow $
- *    $Revision: 1.18.12.2 $
+ *    $Date: 2005/08/02 12:08:58 $ by $Author: glynn $
+ *    $Revision: 1.18.12.3 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -42,8 +42,8 @@
 #include "cac.hh"
 
 //
-template class GenDistEntryTable<RHTNode>;
 #include "hashtblDefs.cc"
+template class GenDistEntryTable<RHTNode>;
 
 //
 ResourceHashTable *resourceTable;
