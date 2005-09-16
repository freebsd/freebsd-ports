--- ./platform/emulator/cac.cc.orig	Tue Apr  6 08:27:38 2004
+++ ./platform/emulator/cac.cc	Sat Sep  3 18:46:08 2005
@@ -15,8 +15,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2004/04/06 12:27:38 $ by $Author: popow $
- *    $Revision: 1.76 $
+ *    $Date: 2004/08/11 14:49:03 $ by $Author: popow $
+ *    $Revision: 1.76.2.2 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -552,9 +552,8 @@
   ret->nextGCStep();
   // an alive board must be copied at every GC step exactly once:
   Assert(ret->isEqGCStep(oz_getGCStep()));
-#else
-  ret->setCopyStep(oz_getCopyStep());
 #endif
+  ret->setCopyStep(oz_getCopyStep());
 
   cacStack.push(ret, PTR_BOARD);
 
@@ -764,52 +763,54 @@
   } else {
     // construct anew, GC"ing keys/values along;
     //
-    int oldSize, newSize;
-    DictNode* old;
-
-    //
-    oldSize = dictHTSizes[sizeIndex];
-    old = table;
+    const int tableSize = dictHTSizes[sizeIndex];
 
     // can be zero too:
-    int tableSize = (int) ((double) entries * GDT_IDEALENTRIES);
-    Assert(tableSize < oldSize);
-    sizeIndex--;
-    while (sizeIndex >= 0 && dictHTSizes[sizeIndex] >= tableSize)
-      sizeIndex--;
-    Assert(sizeIndex < 0 || dictHTSizes[sizeIndex] < tableSize);
-    sizeIndex++;
-    Assert(sizeIndex >= 0 && dictHTSizes[sizeIndex] >= tableSize);
+    int newTableSize = (int) ((double) entries / GDT_IDEALENTRIES);
+    int newSizeIndex = sizeIndex - 1;
+    DictNode* old = table;
+
+    //
+    Assert(newTableSize < tableSize);
+    while (newSizeIndex >= 0 && dictHTSizes[newSizeIndex] >= newTableSize)
+      newSizeIndex--;
+    Assert(newSizeIndex < 0 || dictHTSizes[newSizeIndex] < newTableSize);
+    newSizeIndex++;
+    Assert(newSizeIndex >= 0 && dictHTSizes[newSizeIndex] >= newTableSize);
     // Must not oscillate:
-    Assert(dictHTSizes[sizeIndex] < oldSize);
+    Assert(dictHTSizes[newSizeIndex] < tableSize);
     // Next GC should not attempt compactification:
-    Assert(entries >= (dictHTSizes[sizeIndex] / GDT_MINFULL));
+    Assert(entries >= (dictHTSizes[newSizeIndex] / GDT_MINFULL));
 
     // construct the table anew (keep the 'entries' counter);
-    tableSize = dictHTSizes[sizeIndex];
-    maxEntries = (int) (GDT_MAXENTRIES * tableSize);
-    table = (DictNode *) oz_heapMalloc(tableSize * sizeof(DictNode));
-    for (int i = tableSize; i--; )
-      (void) new (&table[i]) DictNode;
+    newTableSize = dictHTSizes[newSizeIndex];
+
+    //
+    DictHashTable *dht = new DictHashTable(*this);
+    // 'entries' copied;
+    an = (DictNode *) oz_heapMalloc(newTableSize * sizeof(DictNode));
+    for (int i = newTableSize; i--; )
+      (void) new (&an[i]) DictNode;
+    dht->table = an;
+    dht->sizeIndex = newSizeIndex;
+    dht->maxEntries = (int) (GDT_MAXENTRIES * newTableSize);
 
     //
-    for (int i = oldSize; i--; old++) {
+    for (int i = tableSize; i--; old++) {
       if (!old->isEmpty()) {
 	if (!old->isPointer()) {
-	  _cacDictEntry(old);
+	  dht->_cacDictEntry(old);
 	} else {
 	  DictNode *sptr = old->getDictNodeSPtr();
 	  DictNode *eptr = old->getDictNodeEPtr();
 	  do {
-	    _cacDictEntry(sptr++);
+	    dht->_cacDictEntry(sptr++);
 	  } while (sptr < eptr);
 	}
       }
     }
 
     //      
-    DictHashTable *dht = new DictHashTable(*this);
-    dht->table = table;
     return (dht);
   }
   Assert(0);
