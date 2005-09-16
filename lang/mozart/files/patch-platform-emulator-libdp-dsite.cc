--- ./platform/emulator/libdp/dsite.cc.orig	Tue Sep 24 18:30:32 2002
+++ ./platform/emulator/libdp/dsite.cc	Sat Sep  3 18:46:09 2005
@@ -9,8 +9,8 @@
  *    Per Brand, 1998   
  * 
  *  Last change:
- *    $Date: 2002/09/24 22:30:32 $ by $Author: popow $
- *    $Revision: 1.27 $
+ *    $Date: 2005/08/02 12:08:58 $ by $Author: glynn $
+ *    $Revision: 1.27.10.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -51,8 +51,8 @@
 #define SECONDARY_SITE_TABLE_SIZE  6
 
 //
-template class GenDistEntryTable<DSite>;
 #include "hashtblDefs.cc"
+template class GenDistEntryTable<DSite>;
 
 DSiteHashTable* primarySiteTable
 = new DSiteHashTable(PRIMARY_SITE_TABLE_SIZE);
