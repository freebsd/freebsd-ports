$FreeBSD$
 
--- ../../hotspot/src/os/bsd/vm/os_bsd.cpp.orig	Mon Sep 17 21:03:04 2007
+++ ../../hotspot/src/os/bsd/vm/os_bsd.cpp	Tue Sep 18 21:36:51 2007
@@ -2271,13 +2271,7 @@
     if (thread->is_Java_thread()) {
       ThreadBlockInVM tbivm((JavaThread*) thread);
 
-// BSDXXX: Only use pthread_yield here and below if the system thread
-// scheduler gives time slices to lower priority threads when yielding.
-#ifdef __FreeBSD__
-      os_sleep(MinSleepInterval, interruptible);
-#else
       pthread_yield();
-#endif
 
 #if SOLARIS
       // XXX - This code was not exercised during the Merlin RC1
@@ -2297,13 +2291,7 @@
       return 0;
     }
 
-// BSDXXX: Only use pthread_yield here and above if the system thread
-// scheduler gives time slices to lower priority threads when yielding.
-#ifdef __FreeBSD__
-    os_sleep(MinSleepInterval, interruptible);
-#else
     pthread_yield();
-#endif
     return 0;
   }
  
