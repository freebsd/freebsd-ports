--- libraries/ghc-prim/cbits/atomic.c.orig	2019-11-23 20:27:35 UTC
+++ libraries/ghc-prim/cbits/atomic.c
@@ -365,7 +365,7 @@ extern StgWord64 hs_atomicread64(StgWord x);
 StgWord64
 hs_atomicread64(StgWord x)
 {
-#if HAVE_C11_ATOMICS
+#if 0
   return __atomic_load_n((StgWord64 *) x, __ATOMIC_SEQ_CST);
 #else
   return __sync_add_and_fetch((StgWord64 *) x, 0);
@@ -413,7 +413,7 @@ extern void hs_atomicwrite64(StgWord x, StgWord64 val)
 void
 hs_atomicwrite64(StgWord x, StgWord64 val)
 {
-#if HAVE_C11_ATOMICS
+#if 0
   __atomic_store_n((StgWord64 *) x, (StgWord64) val, __ATOMIC_SEQ_CST);
 #else
   while (!__sync_bool_compare_and_swap((StgWord64 *) x, *(StgWord64 *) x, (StgWord64) val));
