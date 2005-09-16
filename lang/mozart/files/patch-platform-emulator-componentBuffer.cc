--- ./platform/emulator/componentBuffer.cc.orig	Mon Mar 11 19:31:50 2002
+++ ./platform/emulator/componentBuffer.cc	Sat Sep  3 18:46:09 2005
@@ -13,8 +13,8 @@
  *    Konstantin Popov 2001
  * 
  *  Last change:
- *    $Date: 2002/03/12 00:31:50 $ by $Author: popow $
- *    $Revision: 1.29 $
+ *    $Date: 2004/08/11 14:49:03 $ by $Author: popow $
+ *    $Revision: 1.29.12.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -277,7 +277,12 @@
 {
   Assert(pbState == PB_Unmarshal);
   DebugCode(pbState = PB_None;);
-  Assert(posMB == last->head() + lastChunkSize);
+  // If zero bytes where read in the last chunk (or, differently put,
+  // the last non-empty chunk was full) - then that last chunk will
+  // never be reached, so 'posMB' will never point to it - because
+  // 'getNext()' advances 'posMB' to a next buffer only when it is
+  // really necessary.
+  Assert(lastChunkSize == 0 || posMB == last->head() + lastChunkSize);
   DebugCode(posMB = (BYTE *) -1;);
   DebugCode(endMB = (BYTE *) -1;);
 }
