--- zthread/include/zthread/Guard.h.orig	2008-02-28 23:15:33.000000000 +0000
+++ zthread/include/zthread/Guard.h	2012-09-24 12:02:46.539117586 +0000
@@ -58,7 +58,7 @@
  public:
 
   template <class T>
-  LockHolder(T& t) : _lock(extract(t)._lock), _enabled(true) { }
+  LockHolder(T& t) : _lock(this->extract(t)._lock), _enabled(true) { }
   
   LockHolder(LockHolder& holder) : _lock(holder._lock), _enabled(true) { }
 
@@ -114,11 +114,11 @@
       if(!Scope2::createScope(l, ms)) {
 
         Scope1::destroyScope(l);
-        return false;
+        return;
 
       }
        
-    return true;
+    return;
 
   }
 
@@ -428,7 +428,7 @@
   template <class U, class V>
   Guard(Guard<U, V>& g) : LockHolder<LockType>(g) {
 
-    LockingPolicy::shareScope(*this, extract(g));
+    LockingPolicy::shareScope(*this, this->extract(g));
     
   }
 
@@ -458,7 +458,7 @@
   template <class U, class V>
   Guard(Guard<U, V>& g, LockType& lock) : LockHolder<LockType>(lock) {
 
-    LockingPolicy::transferScope(*this, extract(g));
+    LockingPolicy::transferScope(*this, this->extract(g));
 
   }
 
