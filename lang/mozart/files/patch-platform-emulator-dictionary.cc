--- ./platform/emulator/dictionary.cc.orig	Tue Dec  9 04:09:34 2003
+++ ./platform/emulator/dictionary.cc	Sat Sep  3 18:46:08 2005
@@ -11,8 +11,8 @@
  *    Konstantin Popov, 2002
  * 
  *  Last change:
- *    $Date: 2003/12/09 09:09:34 $ by $Author: duchier $
- *    $Revision: 1.40 $
+ *    $Date: 2004/07/15 18:56:35 $ by $Author: popow $
+ *    $Revision: 1.40.4.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -214,7 +214,7 @@
   oldEntries = entries;
 
   // can be zero too:
-  int tableSize = (int) ((double) entries * GDT_IDEALENTRIES);
+  int tableSize = (int) ((double) entries / GDT_IDEALENTRIES);
   Assert(tableSize < oldSize);
   sizeIndex--;
   while (sizeIndex >= 0 && dictHTSizes[sizeIndex] >= tableSize)
@@ -345,7 +345,7 @@
   DictNode* acc = out;
 
   //
-  for (int i = dictHTSizes[sizeIndex], ai = 0; i--; ) {
+  for (int i = dictHTSizes[sizeIndex]; i--; ) {
     DictNode* n = &table[i];
     if (!n->isEmpty()) {
       if (!n->isPointer()) {
@@ -429,6 +429,7 @@
 	}
       }
     }
+    Assert(ai == entries);
 
     //
     Order_TaggedRef_By_Feat lt;
@@ -479,6 +480,28 @@
     return (newrec->normalize());
   }
 }
+
+#if defined(DEBUG_CHECK)
+void DictHashTable::verify()
+{
+  int tableSize = dictHTSizes[sizeIndex];
+  int acc = 0;
+
+  for (int i = tableSize; i--; ) {
+    DictNode *n = &table[i];
+    if (!n->isEmpty()) {
+      if (!n->isPointer()) {
+	acc++;
+      } else {
+	DictNode *sptr = n->getDictNodeSPtr();
+	DictNode *eptr = n->getDictNodeEPtr();
+	acc += eptr - sptr;
+      }
+    }
+  }
+  Assert(acc == entries);
+}
+#endif
 
 //  OZ_Term DictHashTable::htFindOutline(OZ_Term key)
 //  {
