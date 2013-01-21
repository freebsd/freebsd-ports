--- src/foreign/zthread/include/zthread/Guard.h.orig      2011-12-02 18:02:37.253022000 +0100
+++ src/foreign/zthread/include/zthread/Guard.h    2013-01-18 19:08:14.000000000 +0100
@@ -108,7 +108,7 @@
   }
 
   template <class LockType>
-  static void createScope(LockHolder<LockType>& l, unsigned long ms) {
+  static bool createScope(LockHolder<LockType>& l, unsigned long ms) {
 
     if(Scope1::createScope(l, ms))
       if(!Scope2::createScope(l, ms)) {
@@ -428,8 +428,8 @@
   template <class U, class V>
   Guard(Guard<U, V>& g) : LockHolder<LockType>(g) {
 
-    LockingPolicy::shareScope(*this, extract(g));
-    
+    LockingPolicy::shareScope(*this, this->extract(g));
+
   }
 
   /**
@@ -458,7 +458,7 @@
   template <class U, class V>
   Guard(Guard<U, V>& g, LockType& lock) : LockHolder<LockType>(lock) {
 
-    LockingPolicy::transferScope(*this, extract(g));
+    LockingPolicy::transferScope(*this, this->extract(g));
 
   }
