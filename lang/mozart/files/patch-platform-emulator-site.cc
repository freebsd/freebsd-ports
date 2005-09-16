--- ./platform/emulator/site.cc.orig	Fri Aug 30 08:55:46 2002
+++ ./platform/emulator/site.cc	Sat Sep  3 18:46:09 2005
@@ -10,8 +10,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2002/08/30 12:55:46 $ by $Author: duchier $
- *    $Revision: 1.27 $
+ *    $Date: 2005/05/31 20:36:05 $ by $Author: duchier $
+ *    $Revision: 1.27.12.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -112,8 +112,8 @@
 }
 
 //
-template class GenDistEntryTable<Site>;
 #include "hashtblDefs.cc"
+template class GenDistEntryTable<Site>;
 
 //
 SiteHashTable* siteTable = 0;
