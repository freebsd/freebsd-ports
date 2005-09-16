--- ./platform/emulator/dictionary.hh.orig	Sat May 17 09:20:38 2003
+++ ./platform/emulator/dictionary.hh	Sat Sep  3 18:46:09 2005
@@ -11,8 +11,8 @@
  *    Konstantin Popov, 2002
  * 
  *  Last change:
- *    $Date: 2003/05/17 13:20:38 $ by $Author: duchier $
- *    $Revision: 1.44 $
+ *    $Date: 2004/07/15 18:56:35 $ by $Author: popow $
+ *    $Revision: 1.44.8.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -629,6 +629,10 @@
   //
   DictHashTable* gCollect(void);
   DictHashTable* sClone(void);
+
+#if defined(DEBUG_CHECK)
+  void verify();
+#endif
 };
   
 
