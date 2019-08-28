--- src/external/rawspeed/src/librawspeed/common/Mutex.h.orig	2019-08-13 19:14:10 UTC
+++ src/external/rawspeed/src/librawspeed/common/Mutex.h
@@ -77,12 +77,12 @@ class CAPABILITY("mutex") Mutex final { (public)
   // Acquire/lock this mutex exclusively.  Only one thread can have exclusive
   // access at any one time.  Write operations to guarded data require an
   // exclusive lock.
-  void __attribute__((const)) Lock() const ACQUIRE() {
+  void Lock() ACQUIRE() {
     // NOP, since there is no mutex. only here to still check for proper locking
   }
 
   // Release/unlock an exclusive mutex.
-  void __attribute__((const)) Unlock() const RELEASE() {
+  void Unlock() RELEASE() {
     // NOP, since there is no mutex. only here to still check for proper locking
   }
 
