--- ../../work/cocktail-9309//./reuse/m2c/rMemory.c	Tue Feb 15 14:26:55 1994
+++ ./reuse/m2c/rMemory.c	Wed Mar 31 22:35:06 2004
@@ -49,6 +49,10 @@
 LONGINT ByteCount;
 # endif
 {
+# ifdef __FreeBSD__
+  /* FreeBSD is suppossed to have its own proper memory manager */
+  return  (ADDRESS)calloc(1,ByteCount);
+# else
   tBlockPtr BlockPtr, CurrentBlock, PreviousBlock, BestBlock, PredecessorBlock;
   CARDINAL ChainNumber;
   LONGINT CurrentBlockSize, BestBlockSize;
@@ -129,6 +133,7 @@
       return (ADDRESS)BlockPtr;
     }
   }
+#endif
 }
 
 void rMemory_Free
@@ -140,6 +145,9 @@
 ADDRESS a;
 # endif
 {
+#ifdef __FREEBSD__
+    free(a);
+#else
   tBlockPtr BlockPtr;
   tLargeBlockRange ChainNumber;
 
@@ -157,6 +165,7 @@
     BlockPtr->Size = ByteCount;
     LargeChain.A[ChainNumber - 6] = (ADDRESS)BlockPtr;
   }
+#endif
 }
 
 void BEGIN_rMemory()
