--- spinlock.c.orig	Tue Mar 27 04:52:56 2001
+++ spinlock.c	Tue Jan 10 09:44:39 2006
@@ -72,8 +72,6 @@
 #endif
 
 #if defined HAS_COMPARE_AND_SWAP
-again:
-
   /* On SMP, try spinning to get the lock. */
 
   if (__pthread_smp_kernel) {
@@ -94,6 +92,8 @@
     lock->__spinlock += (spin_count - lock->__spinlock) / 8;
   }
 
+again:
+
   /* No luck, try once more or suspend. */
 
   do {
@@ -110,7 +110,7 @@
     }
 
     if (self != NULL) {
-      THREAD_SETMEM(self, p_nextlock, (pthread_descr) (oldstatus & ~1L));
+      THREAD_SETMEM(self, p_nextlock, (pthread_descr) oldstatus);
       /* Make sure the store in p_nextlock completes before performing
          the compare-and-swap */
       MEMORY_BARRIER();
@@ -188,7 +188,7 @@
        multiprocessor Alphas) could perform such reordering even though
        the loads are dependent. */
     READ_MEMORY_BARRIER();
-    thr = *ptr;
+    thr = (pthread_descr)((long)(thr->p_nextlock) & ~1L);
   }
   /* Prevent reordering of the load of lock->__status above and
      thr->p_nextlock below */
@@ -198,17 +198,16 @@
     /* If max prio thread is at head, remove it with compare-and-swap
        to guard against concurrent lock operation. This removal
        also has the side effect of marking the lock as released
-       because the new status comes from thr->p_nextlock whose
-       least significant bit is clear. */
+       by clearing the least significant bit. */
     thr = (pthread_descr) (oldstatus & ~1L);
     if (! __compare_and_swap_with_release_semantics
-	    (&lock->__status, oldstatus, (long)(thr->p_nextlock)))
+	    (&lock->__status, oldstatus, (long)(thr->p_nextlock) & ~1L))
       goto again;
   } else {
     /* No risk of concurrent access, remove max prio thread normally.
        But in this case we must also flip the least significant bit
        of the status to mark the lock as released. */
-    thr = *maxptr;
+    thr = (pthread_descr)((long)*maxptr & ~1L);
     *maxptr = thr->p_nextlock;
 
     do {
