--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/rMemory.c	Tue Feb 15 14:26:55 1994
+++ ./reuse/m2c/rMemory.c	Thu Aug  5 18:49:34 2004
@@ -18,28 +18,13 @@
 
 LONGCARD rMemory_MemoryUsed;
 
-#define MinSizeSmallBlock	4
-#define MaxSizeSmallBlock	62
-#define MinSizeLargeBlockLog	6
-#define MaxSizeLargeBlockLog	24
-#define PoolSize	10240
 typedef struct S_1 *tBlockPtr;
 typedef struct S_1 {
     tBlockPtr Successor;
     LONGINT Size;
 } tBlock;
-typedef LONGCARD tSmallBlockRange;
-typedef LONGCARD tLargeBlockRange;
-static struct S_2 {
-    ADDRESS A[MaxSizeSmallBlock - MinSizeSmallBlock + 1];
-} SmallChain;
-static struct S_3 {
-    ADDRESS A[MaxSizeLargeBlockLog - MinSizeLargeBlockLog + 1];
-} LargeChain;
 static ADDRESS PoolFreePtr;
 static ADDRESS PoolEndPtr;
-static tSmallBlockRange i;
-static tLargeBlockRange j;
 
 ADDRESS rMemory_Alloc
 # ifdef __STDC__
@@ -49,86 +34,8 @@
 LONGINT ByteCount;
 # endif
 {
-  tBlockPtr BlockPtr, CurrentBlock, PreviousBlock, BestBlock, PredecessorBlock;
-  CARDINAL ChainNumber;
-  LONGINT CurrentBlockSize, BestBlockSize;
-  tLargeBlockRange j;
-
-  ByteCount = (LONGINT)((BITSET)(ByteCount + General_MaxAlign - 1) & General_AlignMasks.A[General_MaxAlign]);
-  if (ByteCount <= MaxSizeSmallBlock) {
-    if (ByteCount == 0) {
-      ByteCount = General_Max((LONGINT)MinSizeSmallBlock, General_MaxAlign);
-    }
-    if (SmallChain.A[ByteCount - 4] != NIL) {
-      BlockPtr = (tBlockPtr)SmallChain.A[ByteCount - 4];
-      SmallChain.A[ByteCount - 4] = (ADDRESS)BlockPtr->Successor;
-      return (ADDRESS)BlockPtr;
-    } else {
-      if ((LONGINT)(PoolEndPtr - (LONGCARD)PoolFreePtr) < ByteCount) {
-        if ((LONGCARD)(PoolEndPtr - (LONGCARD)PoolFreePtr) >= MinSizeSmallBlock) {
-          rMemory_Free((LONGINT)(PoolEndPtr - (LONGCARD)PoolFreePtr), PoolFreePtr);
-        }
-        PoolFreePtr = rMemory_Alloc((LONGINT)PoolSize);
-        PoolEndPtr = PoolFreePtr + PoolSize;
-      }
-      INC1(PoolFreePtr, (LONGCARD)(ADDRESS)ByteCount);
-      return PoolFreePtr - (LONGCARD)(ADDRESS)ByteCount;
-    }
-  } else {
-    ChainNumber = General_Log2(ByteCount);
-    CurrentBlock = (tBlockPtr)LargeChain.A[ChainNumber - 6];
-    PreviousBlock = (tBlockPtr)ADR(LargeChain.A[ChainNumber - 6]);
-    BestBlock = NIL;
-    BestBlockSize = 1000000000;
-    while (CurrentBlock != NIL) {
-      CurrentBlockSize = CurrentBlock->Size;
-      if (CurrentBlockSize >= ByteCount) {
-        if (CurrentBlockSize == ByteCount) {
-          PreviousBlock->Successor = CurrentBlock->Successor;
-          return (ADDRESS)CurrentBlock;
-        }
-        if (CurrentBlockSize < BestBlockSize) {
-          BestBlock = CurrentBlock;
-          BestBlockSize = CurrentBlockSize;
-          PredecessorBlock = PreviousBlock;
-        }
-      }
-      PreviousBlock = CurrentBlock;
-      CurrentBlock = CurrentBlock->Successor;
-    }
-    if (BestBlock != NIL) {
-      PredecessorBlock->Successor = BestBlock->Successor;
-      if (BestBlockSize - ByteCount >= MinSizeSmallBlock) {
-        rMemory_Free(BestBlockSize - ByteCount, (ADDRESS)BestBlock + (LONGCARD)(ADDRESS)ByteCount);
-      }
-      return (ADDRESS)BestBlock;
-    }
-    for (j = ChainNumber + 1; j <= MaxSizeLargeBlockLog; j += 1) {
-      CurrentBlock = (tBlockPtr)LargeChain.A[j - 6];
-      if (CurrentBlock != NIL) {
-        LargeChain.A[j - 6] = (ADDRESS)CurrentBlock->Successor;
-        if (CurrentBlock->Size - ByteCount >= MinSizeSmallBlock) {
-          rMemory_Free(CurrentBlock->Size - ByteCount, (ADDRESS)CurrentBlock + (LONGCARD)(ADDRESS)ByteCount);
-        }
-        return (ADDRESS)CurrentBlock;
-      }
-    }
-    if (ByteCount < PoolSize) {
-      if ((LONGINT)(PoolEndPtr - (LONGCARD)PoolFreePtr) < ByteCount) {
-        if ((LONGCARD)(PoolEndPtr - (LONGCARD)PoolFreePtr) >= MinSizeSmallBlock) {
-          rMemory_Free((LONGINT)(PoolEndPtr - (LONGCARD)PoolFreePtr), PoolFreePtr);
-        }
-        PoolFreePtr = rMemory_Alloc((LONGINT)PoolSize);
-        PoolEndPtr = PoolFreePtr + PoolSize;
-      }
-      INC1(PoolFreePtr, (LONGCARD)(ADDRESS)ByteCount);
-      return PoolFreePtr - (LONGCARD)(ADDRESS)ByteCount;
-    } else {
-      BlockPtr = (tBlockPtr)rAlloc(ByteCount);
-      INC1(rMemory_MemoryUsed, ByteCount);
-      return (ADDRESS)BlockPtr;
-    }
-  }
+  /* FreeBSD is suppossed to have its own proper memory manager */
+  return  (ADDRESS)calloc(1,ByteCount);
 }
 
 void rMemory_Free
@@ -140,23 +47,7 @@
 ADDRESS a;
 # endif
 {
-  tBlockPtr BlockPtr;
-  tLargeBlockRange ChainNumber;
-
-  ByteCount = (LONGINT)((BITSET)(ByteCount + General_MaxAlign - 1) & General_AlignMasks.A[General_MaxAlign]);
-  BlockPtr = (tBlockPtr)a;
-  if (ByteCount <= MaxSizeSmallBlock) {
-    if (ByteCount == 0) {
-      ByteCount = General_Max((LONGINT)MinSizeSmallBlock, General_MaxAlign);
-    }
-    BlockPtr->Successor = (tBlockPtr)SmallChain.A[ByteCount - 4];
-    SmallChain.A[ByteCount - 4] = (ADDRESS)BlockPtr;
-  } else {
-    ChainNumber = General_Log2(ByteCount);
-    BlockPtr->Successor = (tBlockPtr)LargeChain.A[ChainNumber - 6];
-    BlockPtr->Size = ByteCount;
-    LargeChain.A[ChainNumber - 6] = (ADDRESS)BlockPtr;
-  }
+    free(a);
 }
 
 void BEGIN_rMemory()
@@ -168,12 +59,6 @@
     BEGIN_rSystem();
     BEGIN_IO();
 
-    for (i = MinSizeSmallBlock; i <= MaxSizeSmallBlock; i += 2) {
-      SmallChain.A[i - 4] = (ADDRESS)NIL;
-    }
-    for (j = MinSizeLargeBlockLog; j <= MaxSizeLargeBlockLog; j += 1) {
-      LargeChain.A[j - 6] = (ADDRESS)NIL;
-    }
     PoolFreePtr = (ADDRESS)NIL;
     PoolEndPtr = (ADDRESS)NIL;
     rMemory_MemoryUsed = 0;
