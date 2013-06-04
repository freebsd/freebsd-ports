--- ./libraries/base/GHC/Event/KQueue.hsc.orig	2013-04-18 23:30:14.000000000 +0200
+++ ./libraries/base/GHC/Event/KQueue.hsc	2013-04-30 13:34:11.549185351 +0200
@@ -235,10 +235,11 @@
 #endif
     deriving (Bits, Eq, Num, Show, Storable)
 
-#{enum Filter, Filter
- , filterRead   = EVFILT_READ
- , filterWrite  = EVFILT_WRITE
- }
+filterRead :: Filter
+filterRead = Filter (#const EVFILT_READ)
+
+filterWrite :: Filter
+filterWrite  = Filter (#const EVFILT_WRITE)
 
 data TimeSpec = TimeSpec {
       tv_sec  :: {-# UNPACK #-} !CTime
